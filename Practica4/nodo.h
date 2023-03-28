#pragma once
#include <iostream>
#include <memory>
using namespace std;

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