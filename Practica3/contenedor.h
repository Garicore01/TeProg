/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 22/02/2023
* Practica 2: contendor.h             
*/
#pragma once

#include <iostream>
#include "carga.h"
#include "almacen.h"
using namespace std;

template <typename T>
class Contenedor : public Carga, Almacen<T> { 
protected:
public:
    Contenedor(double volume): Carga("contenedor", volume, 0), Almacen<T>("contenedor", volume, 0) {}
    string mostrar(){
        cout << item.nombre() << " [" << item.volumen() << "m3] [" << item.peso() << "kg] de " << endl;
        for(auto i : this->_content) {
            i->mostrar();
        }
    }
  
};