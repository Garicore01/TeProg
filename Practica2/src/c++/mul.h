/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 22/02/2023
* Practica 2: mul.h              
*/
#pragma once
#include "instruccion.h"


class mul : public Instruccion{
public:
    mul(): Instruccion("mul"){}

    // desapila dos valores de la pila y apila su producto
    void ejecuta(stack<int>& pila,int& PC) const override{ // Con override indico que estoy redefiniendo un metodo de la clase padre.
        int dato1 = pila.top();
        pila.pop();
        int dato2 = pila.top();
        pila.pop();
        pila.push(dato1*dato2);
        PC++;
    }
};