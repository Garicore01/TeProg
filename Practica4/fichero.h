/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 10/04/2023
* Practica 4: fichero.h             
*/
#pragma once
#include <iostream>
#include "Nodo.h"
using namespace std;
#pragma once

/*
Clase Fichero que hereda de Nodo.
Esta clase representa un fichero, en el sistema de ficheros que tiene un tamaño concreto.
*/ 
class Fichero : public Nodo {
    protected:
        int _tamanio;

    public:
        Fichero(string nombre, int tamanio, shared_ptr<Nodo> padre) : Nodo(nombre,padre), _tamanio(tamanio) { }
        void modificarTamanio(int tamanio) {
            _tamanio = tamanio;
        }
        int tamanio() const override { return _tamanio; }
};