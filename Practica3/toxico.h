/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 06/03/2023
* Practica 2: toxico.h             
*/
#pragma once

#include <iostream>
#include "item.h"
using namespace std;

class Toxico : public Item { 
protected:
public:
    Toxico(string name, double volume, double weight): Item(name, volume, weight){}
    string tipo() const override { 
        return "de Toxico";
    }
};