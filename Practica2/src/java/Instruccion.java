/* 
* Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
* NIP: 848905 y 849183
* Asignatura: Tecnología de la Programación
* Fecha: 22/02/2023
* Practica 2: Instruccion.java              
*/
public abstract class Instruccion {
    protected String _nombre;

    public Instruccion(String nombre){ // Clase padre abstracta.
        this._nombre = nombre;
    }
    // Tenemos que pasar el objeto programa, ya que en Java si pasamos datos de tipo primitivo se pasan por valor y como queremos actualizar 
    // el PC, tenemos que pasar el objeto y acceder al atributo y modificarlo ya que los objetos se pasan por referencia.
    public void ejecuta(Programa programa){}  
    public String nombre() {
        return this._nombre;
    }
}