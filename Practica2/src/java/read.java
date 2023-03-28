/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 22/02/2023
* Practica 2: read.java              
*/
import java.util.Scanner;
public class read extends Instruccion {
    public read() {
        super("read");
    }
    /* Pide un valor al usuario por la entrada estándar (indicando al usuario de alguna forma que espera
    una entrada de datos) y lo apila en la pila. */
    public void ejecuta(Programa programa) {
        System.out.print("? ");
        Scanner scanner = new Scanner(System.in);
        int valor = scanner.nextInt();
        programa._pila.push(valor);
        programa._pc++;
    }
}
