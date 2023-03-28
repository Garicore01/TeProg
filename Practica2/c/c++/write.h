/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 22/02/2023
* Practica 2: write.h              
*/
#pragma once
#include "instruccion.h"

class write : public Instruccion{
public:
    write():Instruccion("write"){}

    // desapila un valor de la pila y lo muestra por la salida estándar (pantalla) al usuario
    void ejecuta(stack<int>& pila,int& PC) const override{ // Con override indico que estoy redefiniendo un metodo de la clase padre.
        int dato;
        dato = pila.top();
        pila.pop();
        cout<<dato<<endl;
        PC++;
    }
};