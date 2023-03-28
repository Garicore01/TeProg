/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 06/03/2023
* Practica 2: producto.h             
*/
#pragma once

#include <iostream>
#include "carga.h"
using namespace std;

class Producto : public Carga { 
protected:
public:
    Producto(string name, double volume, double weight): Carga(name, volume, weight){}
};