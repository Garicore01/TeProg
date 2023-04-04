#include <iostream>
#include <memory>
#include <string>
#include "directorio.h"
#include "nodo.h"
#include "fichero.h"
#include "enlace.h"
#include "arbol_ficheros_error.h"
#pragma once
using namespace std;


class Shell {
    protected:
        shared_ptr<Directorio> _directorio;
        shared_ptr<Directorio> _root;
        
        // Metodos que no queremos dar a conocer al usuario.
        vector<string> parsearString(string path){
            vector<string> cadena;
            stringstream input_stringstream(path);
            string lectura;
            if (path[0] == '/' ){
                getline(input_stringstream, lectura, '/'); // Consumo el primer "/"
            }
            while (getline(input_stringstream, lectura, '/')){
                cadena.push_back(lectura);
            }
            return cadena;
        }

        shared_ptr<Directorio> comprobarTipoRutas(string path){
            shared_ptr<Directorio> inicioDirectorio;
            if (path[0] == '/') {
                    inicioDirectorio = _root;
            } else {
                inicioDirectorio = _directorio;
            }
            return inicioDirectorio;        
        }
        
    public:
        Shell(): _root(make_shared<Directorio>("/",nullptr)) {
            _directorio = _root; // Si los construimos a la vez, ERROR.
        };
        string pwd() {
            string ruta = "";
            shared_ptr<Nodo> apuntado = _directorio;
            if (apuntado->padre() != nullptr) {
                ruta = apuntado->nombre() + ruta;
                apuntado = apuntado -> padre();
            }
            while (apuntado->padre() != nullptr){
                ruta = apuntado->nombre() + "/" + ruta;
                apuntado = apuntado -> padre();
            }
            ruta = apuntado->nombre() + ruta;
            return ruta;
        }
        string ls() {
           return _directorio->ls();
        }
        string du() {
            return _directorio->du();
        }
        void vi(string name,int size) {
            _directorio->vi(name,size);
        }
        void mkdir(string name) {
            _directorio->mkdir(name,_directorio);
        }
        void cd(string path) {
            if (path=="..") {
                if ((*_directorio).padre() == nullptr){
                   throw arbol_ficheros_error_ruta_ya_en_root(path);
                }
                _directorio = dynamic_pointer_cast<Directorio>((*_directorio).padre());
            }
            else {
                shared_ptr<Directorio> apuntado;
                apuntado = dynamic_pointer_cast<Directorio>(comprobarTipoRutas(path)->buscarPuntero(parsearString(path),0));
                _directorio = apuntado;
            }
        }
        void ln (string path, string name) {
            shared_ptr<Nodo> apuntado;
            // Parseamos la string y buscamos el puntero al nodo.
            apuntado = _root->buscarPuntero(parsearString(path),0);
            shared_ptr<Enlace> enlace = make_shared<Enlace>(name,apuntado);
            _directorio->anyadir(enlace);
        }
        int stat (string path) {
            shared_ptr<Directorio> apuntado;
            apuntado = dynamic_pointer_cast<Directorio>(comprobarTipoRutas(path)->buscarPuntero(parsearString(path),0));
            return apuntado->tamanio();
        }
        void rm (string path) { 
            shared_ptr<Directorio> apuntado;
            vector<string> cadena = parsearString(path);
            string nombre = cadena.back();
            // Si la longuitud de la cadena es mayor que 1, es que hay que hay que el objetivo a borrar no esta en mi directorio actual.
            if (cadena.size() > 1) {
                cadena.pop_back(); // Elimino del vector el ultimo elemento, ya que es el objetivo a borrar y para tener acceso a el necesito parar en el padre.
                apuntado = dynamic_pointer_cast<Directorio>(comprobarTipoRutas(path)->buscarPuntero(cadena,0)); // Busco el puntero al directorio donde esta el objetivo.
            } else {
                apuntado = _directorio;
            }
            apuntado -> rm(nombre); // Elimino el objetivo.
        }
}; 