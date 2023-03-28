/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 06/03/2023
* Practica 2: item.h             
*/
#pragma once

#include <iostream>
using namespace std;
ostream& operator<<(ostream& os, Item item){
    cout << item.nombre() << " [" << item.volumen() << "m3] [" << item.peso() << "kg] de " << endl; 
}

class Item { 
protected:
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
};

