/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 22/02/2023
* Practica 2: instruccion.h             
*/
#pragma once

#include <iostream>
#include <stack>
using namespace std;

class Instruccion{ //Clase padre abstracta 
protected:
    string _nombre;
    
public:
    Instruccion(string nombre): _nombre(nombre){} // Le pasamos al constructor un string para idenficar el nombre
    virtual string nombre() const{
        return _nombre;
    }
    virtual void ejecuta(stack<int>& pila,int& PC) const =0; 
};















