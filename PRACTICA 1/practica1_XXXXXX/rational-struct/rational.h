/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 04/02/2023
*               
*/
#pragma once

#include <iostream>

// Solucion con atributos publicos.

struct Rational
{
   friend void init(Rational& r);
   friend void init(Rational& r,int num, int den);
   friend void read(Rational& r, std::istream& is);
   friend void write(const Rational& r, std::ostream& os);
   friend Rational add(const Rational& r1, const Rational& r2);
   friend Rational add(const Rational& r, int i);
   friend Rational add(int i, const Rational& r);
   friend Rational sub(const Rational& r1, const Rational& r2);
   friend Rational sub(const Rational& r, int i);
   friend Rational sub(int i, const Rational& r);
   friend Rational mul(const Rational& r1, const Rational& r2);
   friend Rational mul(const Rational& r, int i);
   friend Rational mul(int i, const Rational& r);
   friend Rational div(const Rational& r1, const Rational& r2);
   friend Rational div(const Rational& r, int i);
   friend Rational div(int i, const Rational& r);
   private:
      int numerador;
      int denominador;
      friend int mcd(int a, int b);
      friend int mcm(int a, int b);
      friend void reduce(Rational& r);
};

int mcd(int a, int b);
void reduce(Rational& r);

void init(Rational& r);
void init(Rational& r,int num, int den);

// Entrada - salida
void write(const Rational& r, std::ostream& os);
void read(Rational& r, std::istream& is);

// Operaciones aritmeticas

//add
Rational add(const Rational& r1, const Rational& r2);
Rational add(const Rational& r, int i);
Rational add(int i, const Rational& r);
// sub
Rational sub(const Rational& r1, const Rational& r2);
Rational sub(const Rational& r, int i);
Rational sub(int i, const Rational& r);
// mul
Rational mul(const Rational& r1, const Rational& r2);
Rational mul(const Rational& r, int i);
Rational mul(int i, const Rational& r);
// div
Rational div(const Rational& r1, const Rational& r2);
Rational div(const Rational& r, int i);
Rational div(int i, const Rational& r);


