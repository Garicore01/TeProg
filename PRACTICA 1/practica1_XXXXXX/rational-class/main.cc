/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 08/02/2023           
*/
#include "rational.h"
#include <iostream>

using namespace std;

int main()
{
	Rational	a,b,r;
	char		op;
    bool fin = false;

	while (!fin)
	{
		op = ' ';  //Inicializo el operando a vacio.
        cout << "? ";
        cin >> a >> op >> b;
        switch (op)
        {
        case '+':
            r = a+b;
            break;
        case '-':
            r = a-b;
            break;
        case '*':
            r = a*b;
            break;
        case '/':
            r = a/b;
            break;
        
        default:
            fin = true;
            break;
        }
        if (!fin) {
            cout << "= "<< r;
        }
	}
	return 0;
}

