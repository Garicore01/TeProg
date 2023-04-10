/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 10/04/2023
* Practica 4: arbol_ficheros_error.h             
*/
#include <exception>
#include <iostream>
using namespace std;
#pragma once

/*
Clase que representa una excepción de tipo arbol_ficheros_error la cual va a hacer de padre para
las excepciones que se van a lanzar en el programa
*/
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
/*
Clase que representa una excepción de tipo arbol_ficheros_error y, hace referencia a que el elemento
que se está intentando acceder no existe
*/
class arbol_ficheros_error_elemento_no_existe: public arbol_ficheros_error {
    public:
        arbol_ficheros_error_elemento_no_existe (string mensaje) : 
            arbol_ficheros_error(mensaje){};

};

//no se si es necesaria
/*class arbol_ficheros_error_ruta_no_valida: public arbol_ficheros_error {
    public:
        arbol_ficheros_error_ruta_no_valida (string ruta) : 
            arbol_ficheros_error("La ruta \""+ ruta + "\"introducida no es válida "){}; 
};*/

/*
Clase que representa una excepción de tipo arbol_ficheros_error y, hace referencia a que el elemento
que se esta intentando crear ya existe
*/

class arbol_ficheros_error_carpeta_ya_existe: public arbol_ficheros_error {
    public:
        arbol_ficheros_error_carpeta_ya_existe (string elemento) : 
            arbol_ficheros_error("La carpeta \""+ elemento + "\" que está intentando crear ya existe"){}; 
};
/*
Clase que representa una excepción de tipo arbol_ficheros_error y, hace referencia a que el elemento
que se esta intentando modificar no es un archivo
*/

class arbol_ficheros_error_modificar_elemento_no_valido: public arbol_ficheros_error{
    public:
        arbol_ficheros_error_modificar_elemento_no_valido (string elemento) : 
            arbol_ficheros_error("El elemento \""+elemento +"\" que está intentando modificar no es un archivo"){};
};
/*
Clase que representa una excepción de tipo arbol_ficheros_error y, hace referencia a que el elemento
que se esta intentando acceder no es una carpeta.
*/
class arbol_ficheros_error_elemento_no_es_carpeta: public arbol_ficheros_error{
    public:
        arbol_ficheros_error_elemento_no_es_carpeta (string elemento) : 
            arbol_ficheros_error("El elemento \""+elemento+ "\" al que está intentando acceder no es una carpeta"){};

};

/*
Clase que representa una excepción de tipo arbol_ficheros_error y, hace referencia a que el valor que se le está intentando
asignar a un archivo es negativo
*/
class arbol_ficheros_error_valor_negativo: public arbol_ficheros_error{
    public:
        arbol_ficheros_error_valor_negativo () : 
            arbol_ficheros_error("El valor que esta intentando asignar no es valido, tiene que ser mayor o igual a 0"){};
};
/*
Clase que representa una excepción de tipo arbol_ficheros_error y, hace referencia a que el elemento
que se esta intentando acceder no es un archivo.
*/
class arbol_ficheros_error_ruta_ya_en_root: public arbol_ficheros_error {
    public:
        arbol_ficheros_error_ruta_ya_en_root (string ruta) : 
            arbol_ficheros_error("La ruta \""+ ruta + "\" introducida no es válida, ya estas en la carpeta padre "){}; 
};

