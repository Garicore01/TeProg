/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 22/02/2023
* Practica 2: dup.java              
*/
public class dup extends Instruccion {
    public dup(){
        super("dup");
    }
    // Duplica la cima de la pila (desapila su valor y lo reapila dos veces).
    public void ejecuta(Programa programa) {
        int dato = programa._pila.pop();
        programa._pila.push(dato);
        programa._pila.push(dato);
        programa._pc++;
    }
}
