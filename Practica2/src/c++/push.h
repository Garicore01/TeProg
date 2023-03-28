/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 22/02/2023
* Practica 2: push.h              
*/
#pragma once
#include "instruccion.h"
#include <iostream>
#include <string>
using namespace std;

class push : public Instruccion{
protected:
    int _constante;
public:
    push(int constante): Instruccion("push"),_constante(constante){}
    string nombre()  const override{ // Con override indico que estoy redefiniendo un metodo de la clase padre.
        return _nombre + " " + to_string(_constante);
    }

    // push <c> - apila la constante <c> (parámetro de la instrucción) en la pila.
    void ejecuta(stack<int>& pila,int& PC) const override{ // Con override indico que estoy redefiniendo un metodo de la clase padre.
        pila.push(_constante);
        PC++;
    }
};