/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 08/02/2023       
*/
#pragma once

#include <iostream>
using namespace std;

// Solucion con atributos privados.

class Rational
{
	// Miembros
	int _numerador,_denominador;

	// Funciones auxiliares
	static int mcd(int a, int b);
	static int mcm(int a, int b);
	void reduce();

public:
	// Constructores
	Rational();
	Rational(int num, int den);
	~Rational();
	// Entrada - salida
	void write(std::ostream& os) const;
	void read(std::istream& is);

	// Operadores aritmeticos
	//add
	Rational add(const Rational& that) const;
	Rational add(int i) const;
	//sub
	Rational sub(const Rational& that) const;
	Rational sub(int i) const;
	//mul
	Rational mul(const Rational& that) const;
	Rational mul(int i) const;
	//div
	Rational div(const Rational& that) const;
	Rational div(int i) const;
};

Rational div(int i, const Rational& r);
Rational mul(int i, const Rational& r);
Rational sub(int i, const Rational& r);
Rational add(int i, const Rational& r);


// Operadores aritmeticos
Rational operator+(int i, const Rational& r);
Rational operator+(const Rational& r1, const Rational& r2);
Rational operator+(const Rational& r, int i);

Rational operator-(int i, const Rational& r);
Rational operator-(const Rational& r1, const Rational& r2);
Rational operator-(const Rational& r, int i);

Rational operator/(int i, const Rational& r);
Rational operator/(const Rational& r1, const Rational& r2);
Rational operator/(const Rational& r, int i);

Rational operator*(int i, const Rational& r);
Rational operator*(const Rational& r1, const Rational& r2);
Rational operator*(const Rational& r, int i);

istream& operator>>(istream& is, Rational& r);

ostream& operator<<(ostream& os, const Rational& r);