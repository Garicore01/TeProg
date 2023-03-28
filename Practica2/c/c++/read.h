/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 22/02/2023
* Practica 2: read.h              
*/
#pragma once
#include "instruccion.h"
#include <iostream>
using namespace std;

class read : public Instruccion{
public:
    read():Instruccion("read"){}

    // Pide un valor al usuario por la entrada estándar (indicando al usuario de alguna forma que espera
    // una entrada de datos) y lo apila en la pila.
    void ejecuta(stack<int>& pila,int& PC) const override{ // Con override indico que estoy redefiniendo un metodo de la clase padre.
        cout<<"? ";
        int dato;
        cin >> dato;
        pila.push(dato);
        PC++;
    }
};