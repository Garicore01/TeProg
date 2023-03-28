/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 22/02/2023
* Practica 2: jumpif.java              
*/
public class jumpif extends Instruccion{
    protected int _salto;
    public jumpif(int salto){
        super("jumpif");
        this._salto = salto;
    }
    /* Desapila la cima de la pila, y si su valor es mayor o igual que cero salta la ejecución del
    programa a la línea <salto> (parámetro de la instrucción). */
    public void ejecuta(Programa programa) {
        int dato = programa._pila.pop();
        if (dato >= 0){
            programa._pc = this._salto;
        } else {
            programa._pc++;
        }
    }
    public String nombre(){
        return this._nombre + " " + this._salto;
    }
}
