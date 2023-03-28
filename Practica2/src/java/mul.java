/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 22/02/2023
* Practica 2: mul.java              
*/
public class mul extends Instruccion{
    public mul(){
        super("mul");
    }
    // Desapila dos valores de la pila y apila su producto.
    public void ejecuta(Programa programa) {
        int dato1 = programa._pila.pop();
        int dato2 = programa._pila.pop();
        programa._pila.push(dato1*dato2);
        programa._pc++;
    }
}
