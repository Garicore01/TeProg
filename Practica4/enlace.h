#pragma once
#include <iostream>
#include <memory>
#include "Nodo.h"
using namespace std;

class Enlace : public Nodo {
    protected:
        shared_ptr<Nodo> _apuntado;
    public:
        Enlace(string nombre, shared_ptr<Nodo> apuntado) : Nodo(nombre,nullptr),_apuntado(apuntado) {}
        shared_ptr<Nodo> apuntado() {
            return _apuntado;
        }
        int tamanio() const override { 
            return _apuntado->tamanio();
        }
};