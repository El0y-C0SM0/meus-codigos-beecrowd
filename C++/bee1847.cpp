// erro de 5%
#include <iostream>
 
using namespace std;
 
int main() {
        
    int temperatura_a, temperatura_b, temperatura_c;
    int fator_crescimento_1, fator_crescimento_2;

    cin >> temperatura_a >> temperatura_b >> temperatura_c;

    fator_crescimento_1 = temperatura_b - temperatura_a;
    fator_crescimento_2 = temperatura_c - temperatura_b;

    if(fator_crescimento_1 < fator_crescimento_2)
        cout << ":)" << endl;
    else
        cout << ":(" << endl;

    return 0;
}