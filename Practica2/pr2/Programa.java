import java.util.Stack;

public abstract class Programa {
    protected int _pc;
    protected Stack<Integer> _pila;
    protected Instruccion _instrucciones[];
    protected int _longitud;

    public Programa(){
        this._pila = new Stack<Integer>();
        this._pc = 0;
        this._longitud = 0;
    }
    public void ejecuta(){
        while (this._pc < this._instrucciones.length) {
            this._instrucciones[this._pc].ejecuta(this._pila,this);
        }
    }
    public void listar(){
        for (int i = 0; i < this._instrucciones.length; i++) {
            this._instrucciones[i].nombre();
        }
    }
}

class Programa1 extends Programa{

    public Programa1(){
        super();
        this._longitud = 4;
        this._instrucciones = new Instruccion[_longitud];
        this._instrucciones[0] = new read();
        this._instrucciones[1] = new read();
        this._instrucciones[2] = new add();
        this._instrucciones[3] = new write();
    }
}
class Programa2 extends Programa{
    public Programa2() {
        super();
        this._longitud = 7;
        this._instrucciones = new Instruccion[_longitud];
        this._instrucciones[0] = new read();
        this._instrucciones[1] = new dup();
        this._instrucciones[2] = new write();
        this._instrucciones[3] = new push(-1);
        this._instrucciones[4] = new add();
        this._instrucciones[5] = new dup();
        this._instrucciones[6] = new jumpif(1);
    }
}
class Programa3 extends Programa {
    public Programa3(){
        super();
        this._longitud = 14;
        this._instrucciones = new Instruccion[_longitud];
        this._instrucciones[0] = new push(1);
        this._instrucciones[1] = new read();
        this._instrucciones[2] = new swap();
        this._instrucciones[3] = new over();
        this._instrucciones[4] = new mul();
        this._instrucciones[5] = new swap();
        this._instrucciones[6] = new push(-1);
        this._instrucciones[7] = new add();
        this._instrucciones[8] = new dup();
        this._instrucciones[9] = new push(-2);
        this._instrucciones[10] = new add();
        this._instrucciones[11] = new jumpif(2);
        this._instrucciones[12] = new swap();
        this._instrucciones[13] = new write();
    }
}