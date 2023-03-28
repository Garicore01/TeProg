/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 08/02/2023         
*/

#include "rational.h"
#include <iostream>
using namespace std;

// Helper methods -----------------------
int Rational::mcd(int a, int b) {
   return ( b == 0 ? a : mcd(b,a%b));
}
/*int Rational::mcm(int a, int b) {
   return ((a*b)/mcd(a,b));
}*/

void Rational::reduce() {
   	int mcd=this->mcd(this->_numerador,this->_denominador);
   	this->_numerador=this->_numerador/mcd;
	this->_denominador=this->_denominador/mcd;
	if (this->_numerador<0 and this->_denominador<0){
		this->_numerador=this->_numerador*-1;
		this->_denominador=this->_denominador*-1;
	}
}

// Constructor -----------------------
Rational::Rational() {
	this->_numerador=0;
	this->_denominador=1;
}

Rational::Rational(int num, int den) {
   this->_numerador=num;
   this->_denominador=den;
}
// Destructor --------------------
Rational::~Rational() {}
// Input/output ---------------------------------
void Rational::write(std::ostream& os) const {
 	os << this->_numerador << "/" << this->_denominador << endl;
}

void Rational::read(std::istream& is) {
	char basura;
	is >> this->_numerador >> basura >> this->_denominador;
}



// Add -----------------------
Rational Rational::add(const Rational& that) const {
	//Rational res(((MCM/this->_denominador)*this->_numerador)+((MCM/that._denominador)*that._numerador),MCM);
	Rational res(that._denominador*this->_numerador + this->_denominador*that._numerador,this->_denominador*that._denominador);
	res.reduce();
	return res;
}

Rational Rational::add(int i) const {
	Rational res(i*this->_denominador+this->_numerador,this->_denominador);
	res.reduce();
	return res;
}
Rational add(int i, const Rational& r) {
   return r.add(i);
}

// Subtract -----------------------
Rational Rational::sub(const Rational& that) const {
	Rational res(that._denominador*this->_numerador - this->_denominador*that._numerador,this->_denominador*that._denominador);
	res.reduce();
	return res;
}

Rational Rational::sub(int i) const {
	Rational res(this->_numerador-(i*this->_denominador),this->_denominador);
	res.reduce();
	return res;
}
Rational sub(int i, const Rational& r) {
    r.add(-i);
    return r;
}


// Multiply -------------------------
Rational Rational::mul(const Rational& that) const{
	Rational res(this->_numerador*that._numerador,this->_denominador*that._denominador);
	res.reduce();
	return res;
}
Rational Rational::mul(int i) const{
	Rational res(this->_numerador*i,this->_denominador);
	res.reduce();
	return res;
}
Rational mul(int i, const Rational& r){
    return r.mul(i);
}


// Divide ------------------------------
Rational Rational::div(const Rational& that) const{
	Rational res(this->_numerador*that._denominador,this->_denominador*that._numerador);
	res.reduce();
	return res;
}
Rational Rational::div(int i) const{
	Rational res(this->_denominador,this->_denominador*i);
	res.reduce();
	return res;
}
Rational div(int i, const Rational& r){
	return r.div(i);
}
// Modificación de los operadores

istream& operator>>(istream& is, Rational& r) {
	r.read(is);
	return is;
}


ostream& operator<<(ostream& os,const Rational& r) {
	r.write(os);
	return os;
}

Rational operator+(int i, const Rational& r) {
	return add(i,r);
}
Rational operator+(const Rational& r1, const Rational& r2){
	return r1.add(r2);
}
Rational operator+(const Rational& r, int i) {
	return r.add(i);
}
Rational operator-(int i, const Rational& r){
	return sub(i,r);
}
Rational operator-(const Rational& r1, const Rational& r2){
	return r1.sub(r2);
}
Rational operator-(const Rational& r, int i){
	return r.sub(i);
}
Rational operator/(int i, const Rational& r){
	return div(i,r);
}
Rational operator/(const Rational& r1, const Rational& r2){
	return r1.div(r2);
}
Rational operator/(const Rational& r, int i){
	return r.div(i);
}
Rational operator*(int i, const Rational& r){
	return mul(i,r);
}
Rational operator*(const Rational& r1, const Rational& r2){
	return r1.mul(r2);
}
Rational operator*(const Rational& r, int i){
	return r.mul(i);
}