/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 22/02/2023
* Practica 2: add.h              
*/
#pragma once
#include "instruccion.h"

class add : public Instruccion{
public:
    add():Instruccion("add"){}

    // desapila dos valores de la pila y apila su suma.
    void ejecuta(stack<int>& pila,int& PC) const override{ // Con override indico que estoy redefiniendo un metodo de la clase padre.
        int dato1 = pila.top();
        pila.pop();
        int dato2 = pila.top();
        pila.pop();
        pila.push(dato1+dato2);
        PC++;
    }
};