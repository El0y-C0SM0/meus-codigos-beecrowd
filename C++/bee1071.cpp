#include <iostream>

#define quadrado(x) (x * x) // calcula quadrado
#define abs(x) ((x ^ (x >> 31)) - (x >> 31)) // calcula valor absoluto
#define sinal(x) ((x >> 31) | 1) // calcula o sinal inicial

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int abs_maior = (abs(a) + (a % 2 == 0) - 1);
    int abs_menor = (abs(b) + (b % 2 == 0) - 1);
    int sinal = sinal(a);

    // ordena com base no valor absoluto
    if(abs_maior < abs_menor){ 
        int aux;
        aux = abs_menor;
        abs_menor = abs_maior;
        abs_maior = aux;
        sinal = sinal(b); 
    }

    if(a > 0 && b > 0)
        cout << ((quadrado(abs_maior) - quadrado(abs_menor)) >> 2) << endl;
    else if(a < 0 && b < 0)
        cout << -((quadrado(abs_maior) - quadrado(abs_menor)) >> 2) << endl;
    else if(a < 0 || b < 0) 
        cout << (((quadrado(abs_maior) - quadrado(abs_menor)) >> 2) * sinal) << endl;
    
    return 0;
}