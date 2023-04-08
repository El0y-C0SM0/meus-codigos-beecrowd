// import java.io.IOException;
import java.util.Scanner;

class Bee1018 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int valor = scan.nextInt();
        int[] notas = {100, 50, 20, 10, 5, 2, 1};
        int resto = valor;

        System.out.println(valor);
        for (int i = 0; i < 7; i++) {
            System.out.printf("%d nota(s) de R$ %d,00\n", resto / notas[i], notas[i]);
            resto = resto % notas[i];
        }
    }
}