/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 10/04/2023
* Practica 4: nodo.h             
*/
#pragma once
#include <iostream>
#include <memory>
using namespace std;
#pragma once

/*Clase Nodo
Clase abstracta pura nodo la cual reprenta un elemento en un sistema de archivos y hace de padre de las clases Archivo y Directorio y Enlace
*/
class Nodo {
    protected:
        string _nombre;
        shared_ptr<Nodo> _padre;

    public:
        Nodo(string nombre,shared_ptr<Nodo> padre): _nombre(nombre), _padre(padre){}
        virtual int tamanio() const =0;
        virtual string nombre() {
            return _nombre;
        }
        virtual shared_ptr<Nodo> padre() {
            return _padre;
        }
        
};