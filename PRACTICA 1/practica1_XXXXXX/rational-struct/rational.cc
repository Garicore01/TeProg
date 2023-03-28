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
// Helper functions -----------------------
int mcd(int a, int b) {
   return ( b == 0 ? a : mcd(b,a%b));
}

void reduce(Rational& r) {
   	int MCD=mcd(r.numerador,r.denominador);
	r.numerador=r.numerador/MCD;
	r.denominador=r.denominador/MCD;
	if (r.numerador<0 and r.denominador<0){
		r.numerador=r.numerador*-1;
		r.denominador=r.denominador*-1;
	}
}

// Constructor -----------------------
void init(Rational& r) {
   r.numerador=0;
   r.denominador=1;
}
void init(Rational& r,int num, int den) {
   r.numerador=num;
   r.denominador=den;
}

// Input/output ---------------------------------
void write(const Rational& r, std::ostream& os) {
 	os << r.numerador << "/" << r.denominador << endl;
}

void read(Rational& r, std::istream& is) {
	char basura;
	is >> r.numerador >> basura >> r.denominador;
}

// Add -----------------------
Rational add(const Rational& r1, const Rational& r2) {
	Rational res;
	init(res,r2.denominador*r1.numerador+r1.denominador*r2.numerador,r1.denominador*r2.denominador);
	reduce(res);
	return res;
}

Rational add(const Rational& r, int i) {
	Rational res;
	init(res,i*r.denominador+r.numerador,r.denominador);
	reduce(res);
	return res;
}

Rational add(int i, const Rational& r) {
	return add(r,i);
}

// Subtract -----------------------
Rational sub(const Rational& r1, const Rational& r2){
	Rational res;
	init(res,r2.denominador*r1.numerador-r1.denominador*r2.numerador,r1.denominador*r2.denominador);
	reduce(res);
	return res;
}
Rational sub(const Rational& r, int i){
	Rational res;
	init(res,r.numerador-(i*r.denominador),r.denominador);
	reduce(res);
	return res;
}
Rational sub(int i, const Rational& r){
	Rational res;
	res = add(r,-i);
	reduce(res);
	return res;
}
// Multiply -------------------------
Rational mul(const Rational& r1, const Rational& r2){
	Rational res;
	init(res,r1.numerador*r2.numerador,r1.denominador*r2.denominador);
	reduce(res);
	return res;
}
Rational mul(const Rational& r, int i){
	Rational res;
	init(res,r.numerador*i,r.denominador);
	reduce(res);
	return res;
}
Rational mul(int i, const Rational& r){
	return mul(r,i);
}


// Divide ------------------------------
Rational div(const Rational& r1, const Rational& r2){
	Rational res;
	init(res,r1.numerador*r2.denominador,r1.denominador*r2.numerador);
	reduce(res);
	return res;
}
Rational div(const Rational& r, int i){
	Rational res;
	init(res,r.numerador,r.denominador*i);
	reduce(res);
	return res;
}
Rational div(int i, const Rational& r){
	Rational res;
	init(res,r.denominador*i,r.numerador);
	reduce(res);
	return res;
}
