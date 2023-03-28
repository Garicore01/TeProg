/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 22/02/2023
* Practica 2: Programa3.java              
*/
public class Programa3 extends Programa {
    public Programa3(){
        super();
        this._instrucciones.add(new push(1));
        this._instrucciones.add(new read());
        this._instrucciones.add(new swap());
        this._instrucciones.add(new over());
        this._instrucciones.add(new mul());
        this._instrucciones.add(new swap());
        this._instrucciones.add(new push(-1));
        this._instrucciones.add(new add());
        this._instrucciones.add(new dup());
        this._instrucciones.add(new push(-2));
        this._instrucciones.add(new add());
        this._instrucciones.add(new jumpif(2));
        this._instrucciones.add(new swap());
        this._instrucciones.add(new write());
    }
}
