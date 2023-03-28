/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 22/02/2023
* Practica 2: over.java              
*/
public class over extends Instruccion{
    public over(){
        super("over");
    }
    /*  copia (apila) el valor que está tras la cima de la pila 
    (desapila dos valores, apila el segundo desapilado, después el primero y por último el segundo otra vez). */
    public void ejecuta(Programa programa) {
        int dato1 = programa._pila.pop();
        int dato2 = programa._pila.pop();
        programa._pila.push(dato2);
        programa._pila.push(dato1);
        programa._pila.push(dato2);
        programa._pc++;
    }
}
