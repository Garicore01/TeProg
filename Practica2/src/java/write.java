/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 22/02/2023
* Practica 2: write.java              
*/
public class write extends Instruccion {
    public write(){
        super("write");
    }
    // Desapila un valor de la pila y lo muestra por la salida estándar (pantalla) al usuario.
    public void ejecuta(Programa programa){
        System.out.println(programa._pila.pop());
        programa._pc++;
    }
}
