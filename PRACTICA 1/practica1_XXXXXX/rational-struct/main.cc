/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 04/02/2023
*               
*/
#include "rational.h"
#include <iostream>

using namespace std;

int main()
{
	Rational	a,b,r;
	char		op;

	while (true)
	{
		cout << "? " << flush;

		read(a,cin);
		if (cin.fail())
			break;

		cin >> op;

		read(b,cin);
		if (cin.fail())
			break;

		// Calculo del resultado
		switch (op)
		{
		case '+':
			r = add(a,b);
			break;
		case '-':
			r = sub(a,b);
			break;
		case '*':
			r = mul(a,b);
			break;
		case '/':
			r = div(a,b);
			break;
		
		default:
			cout << "Error";
			break;
		}

		// Escritura del resultado
		cout << "= ";
		write(r,cout);
	}

	return 0;
}

