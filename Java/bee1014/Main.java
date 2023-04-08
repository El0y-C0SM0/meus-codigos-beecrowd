import java.util.Scanner;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scan = new Scanner(System.in);
        int distancia = scan.nextInt();
        double combustivel = scan.nextDouble();
        
        double consumo = distancia / combustivel;
        
        System.out.printf("%.3f km/l\n", consumo);
    }
}