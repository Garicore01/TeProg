/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 22/02/2023
* Practica 2: jumpif.h              
*/
#pragma once
#include "instruccion.h"
#include <iostream>
#include <string>
using namespace std;

class jumpif : public Instruccion{
protected:
    int _salto;
public:
    jumpif(int salto): Instruccion("jumpif"),_salto(salto){}
    string nombre()  const override{ // Con override indico que estoy redefiniendo un metodo de la clase padre.
        return _nombre + " " + to_string(_salto);
    }

    // desapila la cima de la pila, y si su valor es mayor o igual que cero salta la ejecución del
    // programa a la línea <l> (parámetro de la instrucción).
    void ejecuta(stack<int>& pila,int& PC) const override { // Con override indico que estoy redefiniendo un metodo de la clase padre.
        int dato= pila.top();
        pila.pop(); 
        if (dato >= 0){
            PC=_salto;
        }else{
            PC++;
        }
    }
};