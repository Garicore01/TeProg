/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 22/02/2023
* Practica 2: Programa.java              
*/
import java.util.Stack;
import java.util.ArrayList;

public abstract class Programa {
    protected int _pc;
    protected Stack<Integer> _pila;
    protected ArrayList<Instruccion> _instrucciones;

    public Programa(){
        this._pila = new Stack<Integer>();
        this._pc = 0;
        this._instrucciones = new ArrayList<Instruccion>(); // Creo el vector de instrucciones vacio.
    }
    // Ejecuta todas las instrucciones del programa que llama al metodo.
    public void ejecuta(){
        while (this._pc < this._instrucciones.size()) {
            this._instrucciones.get(this._pc).ejecuta(this);
        }
    }
    // Lista los nombres de todas las intrucciones que tiene el programa que llama la metodo.
    public void listar(){
        for (int i = 0; i < this._instrucciones.size(); i++) {
            System.out.println(this._instrucciones.get(i).nombre());
        }
    }
}