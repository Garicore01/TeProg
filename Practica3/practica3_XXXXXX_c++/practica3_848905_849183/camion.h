/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 20/03/2023
* Practica 3: camion.h
*/
#pragma once
#include "almacen.h"
#include "carga.h"
// Clase hija de Almacen de tipo carga(debido a que en un camión se pueden almacenar contenedores y productos estandar) y de Item.
// Especificamos que el tipo de Almacen es un tipo de dato carga, ya que un camión no puede contener a otro camión, solo productos o contenedores.
class Camion : public Almacen<Carga>{ 
protected:
    std::string _name;
    double _volume;
public:
    Camion(double capacity):Almacen(capacity),_name("Camion"),_volume(capacity){} 
    string nombre() const{
        return _name;
    }
    double volumen() const { 
        return _volume;
    }
    // Método peso redefinido para calcular el peso del camión en base al peso de todo lo que tiene almacenado
    double peso() const {
        double weight = 0;
        for (auto i : this->_content) {
            weight += i->peso();
        }
        return weight;
    }

    // Método pintar para imprimir por pantalla el contenido del elemento de almacen.
    void pintar(ostream& os,const int nivel) const {
        if (nivel == 0) {
            os << _name << " [" << _volume << "m3] [" << peso() << "kg]" << endl;
        } else {
            os << setw(nivel) << " "<< _name << " [" << _volume << "m3] [" << peso() << "kg]" << endl;
        }
        for (auto i : this->_content) {
            i->pintar(os,nivel+2);
        }
    }

    friend ostream& operator<<(ostream& os, const Camion& item) {
        item.pintar(os,0);
        return os;
    }; 
};