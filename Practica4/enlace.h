/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 10/04/2023
* Practica 4: enlace.h             
*/
#pragma once
#include <iostream>
#include <memory>
#include "Nodo.h"
using namespace std;
#pragma once

/* 
Clase Enlace, que hereda de la clase Nodo.
Esta clase representa un enlace, que apunta a un fichero, directorio u otro enlace.
*/
class Enlace : public Nodo {
    protected:
        shared_ptr<Nodo> _apuntado;
    public:
        Enlace(string nombre, shared_ptr<Nodo> apuntado) : Nodo(nombre,nullptr),_apuntado(apuntado) {}
        shared_ptr<Nodo> apuntado() {
            return _apuntado;
        }
        // Método que devuelve el tamaño del enlace.
        int tamanio() const override { 
            return _apuntado->tamanio();
        }
};