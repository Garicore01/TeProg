#pragma once
#include <iostream>
#include <string>
#include <map>
#include <memory>
#include "nodo.h"
#include "fichero.h"
#include "enlace.h"
using namespace std;

class Directorio : public Nodo {
    protected:
        map<string,shared_ptr<Nodo>> _hijos;

    public:
        Directorio(string nombre,shared_ptr<Directorio> padre) : Nodo(nombre,padre), _hijos(){}

        int tamanio () const override{ 
            int tamanio = 0;
            for (const auto& [key, value] : _hijos) {
                tamanio += (*value).tamanio();
            }
            return tamanio;
        }
        string ls (){
            string lista;
            //lista += _nombre + "\n";
            for (const auto& [key, value] : _hijos) {
                lista += (*value).nombre()+"\n";
            }
            return lista;
        }

        string du (){
            string lista;
            lista += _nombre + " " + to_string(tamanio()) + "\n";
            for (const auto& [key, value] : _hijos) {
                lista += (*value).nombre() + " " + to_string((*value).tamanio())+"\n";
            }
            return lista;
        }

        void vi (string nombre, int contenido) {
            shared_ptr<Nodo> elemento = _hijos.find(nombre)->second;
            // Voy al enlace y modifico el contenido del fichero.
            while(dynamic_pointer_cast<Enlace>(elemento) != nullptr) {
                shared_ptr<Enlace> Aux = dynamic_pointer_cast<Enlace>(elemento); // Creo un puntero a enlace, para poder acceder a su metodo apuntado.
                elemento = Aux->apuntado();
            }
            if (dynamic_pointer_cast<Fichero>(elemento) != nullptr) { //Entonces es un fichero
                shared_ptr<Fichero> Aux = dynamic_pointer_cast<Fichero>(elemento); // Creo un puntero a fichero, para poder acceder a su metodo modificarTamanio.
                Aux->modificarTamanio(contenido);
            } else { // Entonces es un directorio, por lo que creamos un fichero.
                //shared_ptr<Fichero> Aux = make_shared<Fichero>(nombre,contenido);
                Fichero fich(nombre,contenido);
                //_hijos[nombre] = make_shared<Fichero>(nombre,contenido);
            }
        }

        void mkdir (string nombre,shared_ptr<Directorio> padre) {
            shared_ptr<Directorio> nuevo = make_shared<Directorio>(nombre,padre); // Creamos el directorio.
            _hijos.insert({nombre,nuevo});
        }

        
        void anyadir (shared_ptr<Enlace> enlace) {
            _hijos.insert({enlace->nombre(),enlace});
        }

        void rm (string nombre) {
            _hijos.erase(nombre);
        }

        shared_ptr<Nodo> buscarPuntero (vector<string> cadena,const int i) {
            shared_ptr<Nodo> apuntador;
            apuntador = _hijos.find(cadena[i])->second;
            if (i != (int)cadena.size()-1)  { 
                if ( dynamic_pointer_cast<Directorio>(apuntador) != nullptr){
                    shared_ptr<Directorio> Aux = dynamic_pointer_cast<Directorio>(apuntador); // Creo un puntero a directorio, para poder acceder a su metodo buscarPuntero.
                    apuntador = Aux->buscarPuntero(cadena,i+1);
                }else{
                    //excepcion
                }
            }
            return apuntador; 
        }
};
