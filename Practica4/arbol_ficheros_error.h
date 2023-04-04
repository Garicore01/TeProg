#include <exception>
#include <iostream>
using namespace std;
#pragma once

class arbol_ficheros_error : public exception{
    protected:
        string _mensaje;
    public:
        arbol_ficheros_error (string mensaje) : 
            _mensaje(mensaje) {};
        const char* what() const noexcept override {
            return _mensaje.c_str();
        }  
};

class arbol_ficheros_error_elemento_no_existe: public arbol_ficheros_error {
    public:
        arbol_ficheros_error_elemento_no_existe (string mensaje) : 
            arbol_ficheros_error(mensaje){};

};

//no se si es necesaria
class arbol_ficheros_error_ruta_no_valida: public arbol_ficheros_error {
    public:
        arbol_ficheros_error_ruta_no_valida (string ruta) : 
            arbol_ficheros_error("La ruta \""+ ruta + "\"introducida no es válida "){}; 
};

class arbol_ficheros_error_carpeta_ya_existe: public arbol_ficheros_error {
    public:
        arbol_ficheros_error_carpeta_ya_existe (string elemento) : 
            arbol_ficheros_error("La carpeta \""+ elemento + "\" que está intentando crear ya existe"){}; 
};

class arbol_ficheros_error_modificar_elemento_no_valido: public arbol_ficheros_error{
    public:
        arbol_ficheros_error_modificar_elemento_no_valido (string elemento) : 
            arbol_ficheros_error("El elemento \""+elemento +"\" que está intentando modificar no es un archivo"){};
};

class arbol_ficheros_error_elemento_no_es_carpeta: public arbol_ficheros_error{
    public:
        arbol_ficheros_error_elemento_no_es_carpeta (string elemento) : 
            arbol_ficheros_error("El elemento \""+elemento+ "\" al que está intentando acceder no es una carpeta"){};

};

class arbol_ficheros_error_valor_negativo: public arbol_ficheros_error{
    public:
        arbol_ficheros_error_valor_negativo () : 
            arbol_ficheros_error("El valor que esta intentando asignar no es valido, tiene que ser mayor o igual a 0"){};
};

class arbol_ficheros_error_ruta_ya_en_root: public arbol_ficheros_error {
    public:
        arbol_ficheros_error_ruta_ya_en_root (string ruta) : 
            arbol_ficheros_error("La ruta \""+ ruta + "\" introducida no es válida, ya estas en la carpeta padre "){}; 
};

