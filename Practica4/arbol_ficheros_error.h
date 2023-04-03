#include <exception>
#include <iostream>
using namespace std;
#pragma once

class arbol_ficheros_error : public exception{
    private:
        string _mensaje;
    public:
        arbol_ficheros_error (string mensaje) : _mensaje(mensaje) {};
        const char* what() const noexcept override {
            return _mensaje.c_str();
        }  
};