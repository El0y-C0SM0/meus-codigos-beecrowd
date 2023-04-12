#include <iostream>

#define quadrado(x) (x * x) // calcula quadrado
#define abs(x) ((x ^ (x >> 31)) - (x >> 31)) // calcula valor absoluto
#define sinal(x) ((x >> 31) | 1) // calcula o sinal inicial

using namespace std;

int main() {
    long int a, b;
    cin >> a >> b;

    // ordena com base no valor absoluto
    if(abs(a) < abs(b)){ 
        int aux;
        aux = b;
        b = a;
        a = aux;
    }

    a = (abs(a) + (a % 2 == 0) - 1) * (a / abs(a));
    b = (abs(b) + (b % 2 == 0) - 1) * (b / abs(b));

//    a = (abs(a) + (a % 2 == 0) - 1) * sinal(a);
//    b = (abs(b) + (b % 2 == 0) - 1) * sinal(b);

    // isso é para debugar
    cout << "\tvalor:" << a << endl;
    cout << "\tvalor abs:" << abs(a) << endl;
    cout << "\tvalor:" << b << endl;


    if(a > 0 && b > 0)
        cout << static_cast<int>((quadrado(a) - quadrado(b)) * 0.25) << endl;
    else if(a < 0 && b < 0)
        cout << -(static_cast<int>(quadrado(a) - quadrado(b)) * 0.25) << endl;
    else if(b < 0 || a < 0) 
        cout << static_cast<int>((quadrado(a) - quadrado(b)) * 0.25) << endl;

    
    return 0;
}