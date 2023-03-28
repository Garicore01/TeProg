/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 20/03/2023
* Practica 3: almacen.h
*/
#pragma once
#include <iostream>
#include <vector>
using namespace std;
// Clase intermedia que representa los dos tipos de item para almacenar (contendor y camión)
// Clase de tipo generico ya que en un elemento de tipo almacen podemos guardar distintos tipos de datos.
template <typename T>
class Almacen { 
protected:  
    // Atributos compartidos por todos los almacenes.
    double _freeCapacity;
    vector<T*> _content;
public:
    Almacen(double capacity):_freeCapacity(capacity), _content(){} 
    
    bool guardar( T* elemento) {
        if(elemento->volumen() <= _freeCapacity) {
            _freeCapacity -= elemento->volumen();
            _content.push_back(elemento);
            return true;
        }
        return false;
    }
};