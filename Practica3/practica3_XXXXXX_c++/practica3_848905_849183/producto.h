/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 20/03/2023
* Practica 3: producto.h
*/
#pragma once
#include "carga.h"
using namespace std;
// Clase hija de Carga la cual hereda de otra clase padre Item y representa un producto estandar.
// Esta clase no tiene ni atributos ni métodos propios ya que los hereda de carga y este a su vez de item.
class Producto : public Carga { 
public:
    Producto(string name, double volume, double weight): Carga(name, volume, weight){}
};

// Las clases Tóxico y SerVivo no pueden ser hijas de Carga ya que tenemos que asegurar que no se puedan guardar productos tóxicos y 
// seres vivos

// Clase que representa un producto toxico, que hereda de la clase Item.
class Toxico : public Item { 
public:
    Toxico(string name, double volume, double weight): Item(name, volume, weight){}
    //Método pintar redefinido para imprimir por pantalla el contenido del elemento de almacen.
    string tipo() const override { 
        return " Productos Toxicos";
    }
};