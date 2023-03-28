package JAVA;
import java.io.InputStream;
import java.util.*;
public class main {
    public static void main(String[] args){
        int num,den;
        Rational a,b,r;
        a = new Rational();
        b = new Rational();
        r = new Rational();
        Character op,op2;
        Scanner read = new Scanner(System.in);

        while (true){
            System.out.print("? ");
            a.read(System.in);
            /*num = read.nextInt();
            op2 = read.next();
            den = read.nextInt();
            a = new Rational(num,den);*/
            // comprobar para romper
            op = read.next().charAt(0);
            a.read(System.in);
            switch (op){
                case '+':
                    r = a.add(b);
                case '-':
                    r = a.sub(b);
                case '*':
                    r = a.mul(b);
                case '/':
                    r = a.div(b);
            }
            r.write();
        }
    }
}