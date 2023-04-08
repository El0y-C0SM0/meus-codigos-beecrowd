import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        double coordX = scan.nextDouble();
        double coordY = scan.nextDouble();

        if(coordX == 0 & coordY == 0)
            System.out.println("Origem");
        else if(coordX == 0)
            System.out.println("Eixo Y");
        else if(coordY == 0)
            System.out.println("Eixo X");
        else if(coordX > 0) {
            if(coordY > 0)
                System.out.println("Q1");
            else
                System.out.println("Q4");
        } else {
            if(coordY > 0)
                System.out.println("Q2");
            else
                System.out.println("Q3");
        }
    }
}
