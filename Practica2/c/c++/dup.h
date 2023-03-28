/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 22/02/2023
* Practica 2: dup.h              
*/
#pragma once
#include "instruccion.h"


class dup : public Instruccion{ 
public:
    dup(): Instruccion("dup"){}

    // duplica la cima de la pila (desapila su valor y lo reapila dos veces)
    void ejecuta(stack<int>& pila,int& PC) const override{  // Con override indico que estoy redefiniendo un metodo de la clase padre.
        int dato= pila.top();
        pila.push(dato);
        PC++;
    }
};