/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 22/02/2023
* Practica 2: Programa2.java              
*/
public class Programa2 extends Programa{
    public Programa2() {
        super();
        this._instrucciones.add(new read()) ;
        this._instrucciones.add(new dup());
        this._instrucciones.add(new write());
        this._instrucciones.add(new push(-1));
        this._instrucciones.add(new add());
        this._instrucciones.add(new dup());
        this._instrucciones.add(new jumpif(1));
    }
}
