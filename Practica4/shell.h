/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 10/04/2023
* Practica 4: shell.h             
*/
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

//clase shell que contiene los metodos que se pueden ejecutar en el shell.
class Shell {
    protected:
        // Atributos/metodos que no queremos dar a conocer al usuario.
        shared_ptr<Directorio> _directorio; // Directorio actual.
        shared_ptr<Directorio> _root;    // Directorio raiz.
        
        // método que parsea una string y devuelve un vector de strings con cada elemento de la string separado por "/".
        static vector<string> parsearString(string path){
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
        //metodo que comprueba si la ruta es relativa o absoluta y devuelve el directorio donde se tiene que empezar a buscar.
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
        // Constructor.
        Shell(): _root(make_shared<Directorio>("/",nullptr)) {
            _directorio = _root; // Si los construimos a la vez, ERROR.
        };

        //Método encargado de darnos la ruta en la cual nos encontramos.
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

        // Método encargado de cambiar de directorio con todas sus posibilidades
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
        //Método encargado de crear un enlace en el directorio actual.
        void ln (string path, string name) {
            shared_ptr<Nodo> apuntado;
            vector<string> cadena = parsearString(path);
            string nombre = cadena.back();
            if (cadena.size() > 1) {
                cadena.pop_back(); // Elimino del vector el ultimo elemento, ya que es el objetivo a borrar y para tener acceso a el necesito parar en el padre.
                apuntado = dynamic_pointer_cast<Directorio>(comprobarTipoRutas(path)->buscarPuntero(cadena,0)); // Busco el puntero al directorio donde esta el objetivo.
            } else {
                apuntado = _directorio;
            }
            // Parseamos la string y buscamos el puntero al nodo.
            shared_ptr<Enlace> enlace = make_shared<Enlace>(name,apuntado);
            _directorio->anyadir(enlace);
        }

        //Método encargado de mostrar el tamaño del nodo apuntado por el parametro path.
        int stat (string path) {
            shared_ptr<Nodo> apuntado;
            vector<string> cadena = parsearString(path);
            string nombre = cadena.back();
            if (cadena.size() > 1) {
                cadena.pop_back(); // Elimino del vector el ultimo elemento, ya que es el objetivo a borrar y para tener acceso a el necesito parar en el padre.
                apuntado = comprobarTipoRutas(path)->buscarPuntero(cadena,0); // Busco el puntero al directorio donde esta el objetivo.
            } else {
                apuntado = _directorio;
            }
            return dynamic_pointer_cast<Directorio>(apuntado)->stat(nombre);
        }

        //Método encargado de eliminar el nodo apuntado por el parametro path.
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