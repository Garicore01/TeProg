/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 22/02/2023
* Practica 2: carga.h             
*/
#pragma once

#include <iostream>
#include "item.h"
using namespace std;

class Carga : public Item { 
protected:
public:
    Carga(string name, double volume, double weight): Item(name, volume, weight){}
    string tipo() const override { 
        return "de Carga Estandar";
    }
};
