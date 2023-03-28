#include <iostream>
#include <memory>
#include <string>
#include "directorio.h"
#include "nodo.h"
#include "fichero.h"
#include "enlace.h"
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
            while (getline(input_stringstream, lectura, '/')){ //No sabemos como son las rutas, preguntar
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
        Shell(): _root(make_shared<Directorio>("",nullptr)) {
            _directorio = _root; // Si los construimos a la vez, ERROR.
        };
        string pwd() {
            return _directorio->nombre();
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
                _directorio = dynamic_pointer_cast<Directorio>((*_directorio).padre());
            }
            else {
                shared_ptr<Directorio> apuntado;
                apuntado = dynamic_pointer_cast<Directorio>(comprobarTipoRutas(path)->buscarPuntero(parsearString(path),0));
                _directorio = apuntado;
            }
        }
        void ln(string path, string name) {
            // Parseamos la string
            shared_ptr<Nodo> apuntado;
            apuntado = _root->buscarPuntero(parsearString(path),0); // Caso de Excepción.
            shared_ptr<Enlace> enlace = make_shared<Enlace>(name,apuntado);
            _directorio->anyadir(enlace);
        }
        int stat(string path) {
            shared_ptr<Directorio> apuntado;
            apuntado = dynamic_pointer_cast<Directorio>(comprobarTipoRutas(path)->buscarPuntero(parsearString(path),0));
            return apuntado->tamanio();
        }
        void rm(string path){
            shared_ptr<Directorio> apuntado;
            string nombre = parsearString(path).back();
            apuntado = dynamic_pointer_cast<Directorio>(comprobarTipoRutas(path)->buscarPuntero(parsearString(path),0));
            apuntado->rm(nombre);
        }
}; 
