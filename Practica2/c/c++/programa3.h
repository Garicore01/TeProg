/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 22/02/2023
* Practica 2: programa3.h              
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
#include "Swap.h"
#include "over.h"
#include "mul.h"

class programa3 :public programa{
public:
    programa3():programa(){
        _longitud=14;
        _instrucciones= new Instruccion*[_longitud];
        _instrucciones[0] = new push(1);
        _instrucciones[1] = new read();
        _instrucciones[2] = new Swap();
        _instrucciones[3] = new over();
        _instrucciones[4] = new mul();
        _instrucciones[5] = new Swap();
        _instrucciones[6] = new push(-1);
        _instrucciones[7] = new add();
        _instrucciones[8] = new dup();
        _instrucciones[9] = new push(-2);
        _instrucciones[10] = new add();
        _instrucciones[11] = new jumpif(2);
        _instrucciones[12] = new Swap();
        _instrucciones[13] = new write();
    }
    ~programa3() { 
        for (int i = 0; i < this->_longitud; i++){
            delete _instrucciones[i];
        }
        delete []_instrucciones;
    }

};