/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 22/02/2023
* Practica 2: push.java              
*/
public class push extends Instruccion {
    protected int _constante; // Necesito un atributo nuevo para guardar la constante.
    public push(int constante){
        super("push");
        this._constante = constante;
    }
    // Apila la constante (parámetro de la instrucción) en la pila.
    public void ejecuta(Programa programa){
        programa._pila.push(this._constante);
        programa._pc++;
    }
    public String nombre(){
        return this._nombre + " " + this._constante;
    }
}
