import java.util.Scanner;
import java.util.Stack;

public abstract class Instruccion {
    protected String _nombre;

    public Instruccion(String nombre){
        this._nombre = nombre;
    }
    public void ejecuta(Stack<Integer> pila, Programa programa){}
    public void nombre() {
        System.out.println(this._nombre);
    }
}
class add extends Instruccion {
    public add(){
        super("add");
    }
    public void ejecuta(Stack<Integer> pila, Programa programa){
        int dato1 = pila.pop();
        int dato2 = pila.pop();
        pila.push(dato1+dato2);
        programa._pc++;
    }
}
class read extends Instruccion {
    public read() {
        super("read");
    }
    public void ejecuta(Stack<Integer> pila, Programa programa) {
        System.out.print("? ");
        Scanner scanner = new Scanner(System.in);
        int valor = scanner.nextInt();
        pila.push(valor);
        programa._pc++;
    }
}
class write extends Instruccion {
    public write(){
        super("write");
    }
    public void ejecuta(Stack<Integer> pila, Programa programa){
        System.out.println(pila.pop());
        programa._pc++;
    }
}
class push extends Instruccion {
    protected int _constante; // Necesito un atributo nuevo para guardar la constante.
    public push(int constante){
        super("push");
        this._constante = constante;
    }
    public void ejecuta(Stack<Integer> pila, Programa programa){
        pila.push(this._constante);
        programa._pc++;
    }
    public void nombre(){
        System.out.println(this._nombre + " " + this._constante);
    }
}
class dup extends Instruccion {
    public dup(){
        super("dup");
    }
    public void ejecuta(Stack<Integer> pila, Programa programa) {
        int dato = pila.pop();
        pila.push(dato);
        pila.push(dato);
        programa._pc++;
    }
}
class jumpif extends Instruccion{
    protected int _salto;
    public jumpif(int salto){
        super("jumpif");
        this._salto = salto;
    }
    public void ejecuta(Stack<Integer> pila, Programa programa) {
        int dato = pila.pop();
        if (dato >= 0){
            programa._pc = this._salto;
        } else {
            programa._pc++;
        }
    }
    public void nombre(){
        System.out.println(this._nombre + " " + this._salto);
    }
}
class mul extends Instruccion{
    public mul(){
        super("mul");
    }
    public void ejecuta(Stack<Integer> pila, Programa programa) {
        int dato1 = pila.pop();
        int dato2 = pila.pop();
        pila.push(dato1*dato2);
        programa._pc++;
    }
}
class swap extends Instruccion{
    public swap(){
        super("swap");
    }
    public void ejecuta(Stack<Integer> pila, Programa programa) {
        int dato1 = pila.pop();
        int dato2 = pila.pop();
        pila.push(dato1);
        pila.push(dato2);
        programa._pc++;
    }
}
class over extends Instruccion{
    public over(){
        super("over");
    }
    public void ejecuta(Stack<Integer> pila, Programa programa) {
        int dato1 = pila.pop();
        int dato2 = pila.pop();
        pila.push(dato2);
        pila.push(dato1);
        pila.push(dato2);
        programa._pc++;
    }
}
