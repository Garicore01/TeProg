/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 22/02/2023
* Practica 2: swap.java              
*/
public class swap extends Instruccion{
    public swap(){
        super("swap");
    }
    // Intercambia dos elementos en la cima de la pila (desapila dos valores y los reapila en orden inverso).
    public void ejecuta(Programa programa) {
        int dato1 = programa._pila.pop();
        int dato2 = programa._pila.pop();
        programa._pila.push(dato1);
        programa._pila.push(dato2);
        programa._pc++;
    }
}
