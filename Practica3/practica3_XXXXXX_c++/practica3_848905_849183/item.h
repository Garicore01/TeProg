/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 20/03/2023
* Practica 3: item.h
*/
#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
// Clase padre que representa los distintos tipos de item que tenemos.
class Item { 
protected:
    // Atributos compartidos por todos los item.
    string _name;
    double _volume;
    double _weight;
    
public:
    Item(string name, double volume, double weight): _name(name), _volume(volume), _weight(weight){} 
    virtual string nombre() const{
        return _name;
    }
    virtual double volumen() const { 
        return _volume;
    }
    virtual double peso() const {
        return _weight;
    }
    virtual string tipo() const {
        return "";
    }
    virtual void pintar(ostream& os,const int nivel) const {
        os << setw(nivel) << " " <<_name << " [" << _volume << "m3] [" << peso() << "kg]" <<endl;
    }
    friend ostream& operator<<(ostream& os, const Item& item) {
        item.pintar(os,0);
        return os;
    }; 
};