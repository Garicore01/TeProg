/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 06/03/2023
* Practica 2: camion.h             
*/
#pragma once

#include <iostream>
#include <vector>
#include "almacen.h"
#include "carga.h"
using namespace std;

class Camion : public Almacen<Carga>{ 
protected:  
public:
    Camion(double capacity):Almacen("camion",capacity,0){} 
};