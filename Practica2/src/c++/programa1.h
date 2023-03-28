/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 22/02/2023
* Practica 2: programa1.h              
*/
#pragma once
#include "programa.h"
#include "read.h"
#include "add.h"
#include "write.h"
class programa1 : public programa{
public:

    programa1():programa(){
        _longitud=4;
        _instrucciones= new Instruccion*[_longitud];
        _instrucciones[0] = new read();
        _instrucciones[1] = new read();
        _instrucciones[2] = new add();
        _instrucciones[3] = new write();
    }
    ~programa1() { 
        for (int i = 0; i < this->_longitud; i++){
            delete _instrucciones[i];
        }
        delete []_instrucciones;
    }

};