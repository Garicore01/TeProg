/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 20/03/2023
* Practica 3: servivo.h
*/
#pragma once
#include "item.h"
using namespace std;
// Clase hija de item la cual representa a un ser vivo el cual puede ser cargado en un contenedor
class SerVivo : public Item { 
public:
    SerVivo(string name, double volume, double weight): Item(name, volume, weight){}
    
    // Método tipo redefinido de la clase Item
    string tipo() const override { 
        return "Seres Vivos";
    }
    
};