/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 10/04/2023
* Practica 4: directorio.h             
*/
#pragma once
#include <iostream>
#include <string>
#include <map>
#include <memory>
#include "nodo.h"
#include "fichero.h"
#include "enlace.h"
#include "arbol_ficheros_error.h"
using namespace std;

/*
Clase Directorio, que hereda de la clase Nodo.
Esta clase representa un directorio, que puede contener ficheros, enlaces y otros directorios.
*/
class Directorio : public Nodo {
    protected:
        map<string,shared_ptr<Nodo>> _hijos; // Diccionario de punteros a nodos, que contiene los hijos del directorio.

    public:
        Directorio(string nombre,shared_ptr<Directorio> padre) : Nodo(nombre,padre), _hijos(){}

        
        // Método que devuelve el tamañio del directorio.
        int tamanio () const override { 
            int tamanio = 0;
            for (const auto& [key, value] : _hijos) {
                tamanio += (*value).tamanio();
            }
            return tamanio;
        }
        // Método que devuelve un string con el listado de los hijos del directorio.
        string ls (){
            string lista;
            //lista += _nombre + "\n";
            for (const auto& [key, value] : _hijos) {
                lista += (*value).nombre()+"\n";
            }
            return lista;
        }
        // Método que devuelve un string con el listado de los hijos del directorio, junto con su tamaño.
        string du (){
            string lista;
            for (const auto& [key, value] : _hijos) {
                lista += (*value).nombre() + " " + to_string((*value).tamanio())+"\n";
            }
            return lista;
        }
        // Método que modifica el tamaño de un fichero con nombre <nombre>, si existe, sino crea un nuevo fichero con ese nombre y tamaño.
        void vi (string nombre, int size) {
            if (size < 0) {
                throw arbol_ficheros_error_valor_negativo();
            }
            auto it = _hijos.find(nombre);
            if (it == _hijos.end()) { // No existe el fichero, entonces lo creo
                _hijos[nombre] = make_shared<Fichero>(nombre,size);
            } else {
                shared_ptr<Nodo> elemento = it->second;
                // Voy al enlace y modifico el contenido del fichero.
                while(dynamic_pointer_cast<Enlace>(elemento) != nullptr) {
                    shared_ptr<Enlace> Aux = dynamic_pointer_cast<Enlace>(elemento); // Creo un puntero a enlace, para poder acceder a su metodo apuntado.
                    elemento = Aux->apuntado();
                }
                if (dynamic_pointer_cast<Fichero>(elemento) != nullptr) { //Entonces es un fichero
                    shared_ptr<Fichero> Aux = dynamic_pointer_cast<Fichero>(elemento); // Creo un puntero a fichero, para poder acceder a su metodo modificarTamanio.
                    Aux->modificarTamanio(size);
                 } else { // Caso de excepción.
                    throw arbol_ficheros_error_modificar_elemento_no_valido(nombre);
                 }
            }
        }
        // Método que crea un nuevo directorio con nombre <nombre>.
        void mkdir (string nombre,shared_ptr<Directorio> padre) {
            if (_hijos.find(nombre) == _hijos.end()) { //Caso de que no existe ya el nombre.
                shared_ptr<Directorio> nuevo = make_shared<Directorio>(nombre,padre); // Creamos el directorio.
                _hijos.insert({nombre,nuevo}); 
            } else {
                throw arbol_ficheros_error_carpeta_ya_existe(nombre);
            }
        }

        // Método que añade un hijo al directorio.
        void anyadir (shared_ptr<Enlace> enlace) {
            _hijos.insert({enlace->nombre(),enlace});
        }
        // Método que elimina un hijo del directorio.
        void rm (string nombre) {
            _hijos.erase(nombre);
        }
        // Método que devuelve un puntero al hijo con nombre <nombre>.
        /*shared_ptr<Nodo> buscarPuntero (vector<string> cadena,const int i) {
            auto buscar = _hijos.find(cadena[i]);
            if (buscar != _hijos.end()) {
                shared_ptr<Nodo> apuntador = buscar->second;
                int tamanio_v = cadena.size()-1;
                if (i != tamanio_v)  { 
                    if ( dynamic_pointer_cast<Directorio>(apuntador) != nullptr) {
                        apuntador = dynamic_pointer_cast<Directorio>(apuntador)->buscarPuntero(cadena,i+1);
                    } else {
                        throw arbol_ficheros_error_elemento_no_es_carpeta(cadena[i]);
                    }
                } else if ( dynamic_pointer_cast<Directorio>(apuntador) == nullptr) {
                        throw arbol_ficheros_error_elemento_no_es_carpeta(cadena[i]);
                }
                return apuntador;
            } else {
                throw arbol_ficheros_error_elemento_no_existe("La ruta " + cadena[i] + " no existe.");
            }
        }*/

        shared_ptr<Nodo> buscarPuntero (vector<string> cadena,const int i) {
            auto buscar = _hijos.find(cadena[i]);
            if (buscar != _hijos.end()) {
                shared_ptr<Nodo> apuntador = buscar->second;
                int tamanio_v = cadena.size();
                if (i != tamanio_v)  { 
                    if ( dynamic_pointer_cast<Directorio>(apuntador) != nullptr) {
                        apuntador = dynamic_pointer_cast<Directorio>(apuntador)->buscarPuntero(cadena,i+1);
                    } else {
                        throw arbol_ficheros_error_elemento_no_es_carpeta(cadena[i]);
                    }
                }
                return apuntador;
            } else {
                throw arbol_ficheros_error_elemento_no_existe("La ruta " + cadena[i] + " no existe.");
            }
        }

        int stat (string nombre) {
            if (nombre == _nombre) {
                return tamanio();
            } else {
                return _hijos[nombre]->tamanio();
            }
        }
};

        