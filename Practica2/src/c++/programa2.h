/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 22/02/2023
* Practica 2: programa2.h              
*/
#pragma once
#include "programa.h"
#include "read.h"
#include "dup.h"
#include "write.h"
#include "write.h"
#include "push.h"
#include "add.h"
#include "jumpif.h"

class programa2 :public programa{
public:
    programa2():programa(){
        _longitud=7;
        _instrucciones= new Instruccion*[_longitud];
        _instrucciones[0] = new read();
        _instrucciones[1] = new dup();
        _instrucciones[2] = new write();
        _instrucciones[3] = new push(-1);
        _instrucciones[4] = new add();
        _instrucciones[5] = new dup();
        _instrucciones[6] = new jumpif(1);
    }
    ~programa2() { 
        for (int i = 0; i < this->_longitud; i++){
            delete _instrucciones[i];
        }
        delete []_instrucciones;
    }

};