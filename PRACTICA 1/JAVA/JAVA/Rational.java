/*
 * Nombre y Apellido: Gari Arellano Zubía y Alain Cascán Zalewska
 * NIP: 848905 y 849183
 * Asignatura: Tecnología de la Programación
 * Fecha: 04/02/2023
 *
 */
// Solucion con atributos privados.
package JAVA;
import java.io.*;
import java.util.*;
import java.util.regex.Pattern;

public class Rational
{
    // Miembros
    private int _numerador;
    private int _denominador;

    // Funciones auxiliares

    // Helper methods -----------------------
    private static int mcd(int a, int b)
    {
        return (b == 0 ? a : mcd(b, a % b));
    }
    private static int mcm(int a, int b)
    {
        return ((a * b) / mcd(a, b));
    }
    private void reduce()
    {
        int MCD = this.mcd(this._numerador,this._denominador);
        this._numerador = this._numerador / MCD;
        this._denominador = this._denominador / MCD;
        if (this._numerador < 0 && this._denominador < 0)
        {
            this._numerador = this._numerador * -1;
            this._denominador = this._denominador * -1;
        }
    }

    // Constructores

    // Constructor -----------------------
    public Rational()
    {
        this._numerador = 0;
        this._denominador = 1;
    }
    public Rational(int num, int den)
    {
        this._numerador = num;
        this._denominador = den;
    }
    // Input/output ---------------------------------
    public final void write()
    {
        System.out.print(this._numerador);
        System.out.print('/');
        System.out.print(this._denominador);
        
    }
    public final void read(InputStream is)// throws IOException
    {
        BufferedReader leer = new BufferedReader(new InputStreamReader(is));
        Pattern p = Pattern.compile("[ ]|[+]|[\n]");
        String[] datos = leer.readLine().split(p);
        if(datos.length == 2){
           this._numerador = Integer.parseInt(datos[0]);
           System.out.println(_numerador);
           this._denominador = Integer.parseInt(datos[1]);
           System.out.println(_denominador);
        }
        

    }

    // Operadores aritmeticos
    //add

    // Add -----------------------
    public final Rational add(Rational that)
    {
        int MCM = mcm(this._denominador, that._denominador);
        Rational res = new Rational(((MCM/this._denominador) * this._numerador) + ((MCM/that._denominador) * that._numerador), MCM);
        res.reduce();
        return res;
    }
    public final Rational add(int i)
    {
        Rational res = new Rational(i * this._denominador + this._numerador, this._denominador);
        res.reduce();
        return res;
    }

    // Subtract ----------------------
    public final Rational sub(Rational that)
    {
        int MCM = mcm(this._denominador, that._denominador);
        Rational res = new Rational((MCM * this._numerador) - (MCM * that._numerador), MCM);
        res.reduce();
        return res;
    }
    public final Rational sub(int i)
    {
        Rational res = new Rational(this._numerador - (i * this._denominador), this._denominador);
        res.reduce();
        return res;
    }

    // Multiply -------------------------
    public final Rational mul(Rational that)
    {
        Rational res = new Rational(this._numerador * that._numerador, this._denominador * that._denominador);
        res.reduce();
        return res;
    }
    public final Rational mul(int i)
    {
        Rational res = new Rational(this._numerador * i, this._denominador);
        res.reduce();
        return res;
    }

    // Divide ------------------------------
    public final Rational div(Rational that)
    {
        Rational res = new Rational(this._numerador * that._denominador, this._denominador * that._numerador);
        res.reduce();
        return res;
    }
    public final Rational div(int i)
    {
        Rational res = new Rational(this._denominador, this._denominador * i);
        res.reduce();
        return res;
    }
}
