/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 22/02/2023
* Practica 2: Programa1.java              
*/
public class Programa1 extends Programa{
    public Programa1(){
        super();
        this._instrucciones.add(new read());
        this._instrucciones.add(new read());
        this._instrucciones.add(new add());
        this._instrucciones.add(new write()) ;
    }
}
