/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 06/03/2023
* Practica 2: almacen.h             
*/
#pragma once

#include <iostream>
#include <vector>
#include "carga.h"
using namespace std;

template <typename T>
class Almacen { 
protected:  
    string _name;
    double _weight;
    double _freeCapacity;
    double _capacity;
    vector<T*> _content;
public:
    Almacen(string name, double capacity, double weight):_name(name),_freeCapacity(capacity),_capacity(capacity),_weight(weight), _content(){} 
    virtual string nombre() const{
        return _name;
    }
    virtual double volumen() const { 
        return _capacity;
    }
    virtual double peso() const {
        return _weight;
    }
    
    bool guardar(const T& elemento) {
        if(elemento.volumen() <= _freeCapacity) {
            _freeCapacity -= elemento.volumen();
            _content.push_back(elemento);
            _weight += elemento.peso();
            return true;
        }
        return false;
    }
};