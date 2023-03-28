/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 22/02/2023
* Practica 2: main.cc              
*/
#include "programa1.h"
#include "programa2.h"
#include "programa3.h"
#include <iostream>
using namespace std;
int main(){


    programa* program1 = new programa1();
    programa* program2 = new programa2();
    programa* program3 = new programa3();

    cout<<"Programa:" << endl;
    program1->listar();
    cout<< endl <<"Ejecuta: "<<endl;
    program1->ejecutar();

    cout << "Programa:" << endl;
    program2->listar();
    cout << "Ejecuta:" << endl;
    program2->ejecutar();

    cout << "Programa:" << endl;
    program3->listar();
    cout<<"Ejecuta:" << endl;
    program3->ejecutar();
}