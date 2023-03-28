#pragma once
#include <iostream>
#include "Nodo.h"
using namespace std;

class Fichero : public Nodo {
    protected:
        int _tamanio;

    public:
        Fichero(string nombre, int tamanio) : Nodo(nombre,nullptr), _tamanio(tamanio) {}
        void modificarTamanio(int tamanio) {
            _tamanio = tamanio;
        }
        int tamanio() const override { return _tamanio; }
};