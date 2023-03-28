public class Main {
    public static void main(String[] args) {
        Programa programa1 = new Programa1();
        Programa programa2 = new Programa2();
        Programa programa3 = new Programa3();

        System.out.println("Programa:");
        programa1.listar();
        System.out.println("Ejecuta:");
        programa1.ejecuta();

        System.out.println("Programa:");
        programa2.listar();
        System.out.println("Ejecuta:");
        programa2.ejecuta();

        System.out.println("Programa:");
        programa3.listar();
        System.out.println("Ejecuta:");
        programa3.ejecuta();
    }
}