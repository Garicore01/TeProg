/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 20/03/2023
* Practica 3: carga.h
*/
#pragma once
#include <iostream>
#include "item.h"
using namespace std;
// Clase intermedia que representa lo que es una carga estandar (que puede ser un producto estandar o un contenedor).
class Carga : public Item { 
public:
    Carga(string name, double volume, double weight): Item(name, volume, weight){}
    string tipo() const override { 
        return "Carga Estandar";
    }  
};