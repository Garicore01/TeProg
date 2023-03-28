/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 22/02/2023
* Practica 2: over.h              
*/
#pragma once
#include "instruccion.h"
class over : public Instruccion{
public:
    over(): Instruccion("over"){}

    // copia (apila) el valor que está tras la cima de la pila (desapila dos valores, apila el segundo desapilado,
    // después el primero y por último el segundo otra vez)
    void ejecuta(stack<int>& pila,int& PC) const override{ // Con override indico que estoy redefiniendo un metodo de la clase padre.
        int dato1= pila.top();
        pila.pop();
        int dato2 = pila.top();
        pila.push(dato1);
        pila.push(dato2);
        PC++;
    }

};