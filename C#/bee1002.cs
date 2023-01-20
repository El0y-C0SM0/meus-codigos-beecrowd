using System; 

class URI {
    static void Main(string[] args) { 
        const double PI =  3.14159;

        double raio = Convert.ToDouble(Console.ReadLine());
        
        double area = Math.Pow(raio, 2) * PI;
        
        Console.WriteLine($"A={area.ToString("0.0000")}");
    }
}