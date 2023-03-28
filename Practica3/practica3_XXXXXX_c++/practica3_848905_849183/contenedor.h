/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 20/03/2023
* Practica 3: contenedor.h
*/
#pragma once
#include "almacen.h"
#include "carga.h"
using namespace std;
// Clase que representa un contendor, al ser un elemento para almacenar y una carga, hereda de las clases Almacen y Carga (Carga hereda de Item)
// Clase de tipo generico ya que el contenedor puede guardar mas de un tipo de dato, utilizamos el parametro T para instanciar la clase 
// Almacen con el mismo tipo de dato que nos pasan a Contenedor, ya que un Contenedor puede guardar otro.
template <typename T>
class Contenedor : public Almacen<T>, public Carga  { 
public:
    Contenedor(double volume): Almacen<T>(volume), Carga("Contenedor", volume, 0) {}
    //Método pintar redefinido para imprimir por pantalla el contenido del elemento de almacen.
    void pintar(ostream& os, const int nivel) const override {
        os << setw(nivel) << " " << _name << " [" << _volume << "m3] [" << peso() << "kg] de " << this->_content.front()->tipo() << endl;
        for (auto i : this->_content) {
            i->pintar(os, nivel+2);
        }
    }
    
    //Método peso redefinido para calcular el peso del camión en base al peso de todo lo que tiene almacenado
    double peso() const override {
        double weight = 0;
        for (auto i : this->_content) {
            weight += i->peso();
        }
        return weight;
    }
};
