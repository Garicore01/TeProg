/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 22/02/2023
* Practica 2: add.java              
*/
public class add extends Instruccion {
    public add(){
        super("add");
    }
    // Desapila dos valores de la pila y apila su suma.
    public void ejecuta(Programa programa){
        int dato1 = programa._pila.pop();
        int dato2 = programa._pila.pop();
        programa._pila.push(dato1+dato2);
        programa._pc++;
    }
}
