/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 22/02/2023
* Practica 2: programa.h              
*/
#pragma once

#include <iostream>
#include <stack>
#include "instruccion.h"
using namespace std;

class programa{
protected:
    stack<int> _pila;
    int _PC;
    Instruccion** _instrucciones;
    int _longitud;
public:
    programa():_pila(),_longitud(0),_PC(0){
        _instrucciones = nullptr;
    }
    virtual ~programa(){}
    void ejecutar(){
        while (_PC < _longitud){
            _instrucciones[_PC]->ejecuta(_pila,_PC);
        }
    }
    
    void listar() const{
        for (int i = 0; i < _longitud; i++){
            cout << _instrucciones[i]->nombre() << endl;
        }
    }
};





