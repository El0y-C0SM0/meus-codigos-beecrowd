#include <iostream>
 
using namespace std;
 
int main() {
    int num_casos;
    int populacao_a, populacao_b;
    double crescimento_a, crescimento_b;

    cin >> num_casos;
    for(int i = 0; i < num_casos; i++) {
        cin >> populacao_a >> populacao_b >> crescimento_a >> crescimento_b;

        int tempo = 0;
        crescimento_a /= 100;
        crescimento_b /= 100;

        while(populacao_a <= populacao_b && tempo <= 101) {
            populacao_a += crescimento_a * populacao_a; 
            populacao_b += crescimento_b * populacao_b; 
            tempo++;
        }

        if(tempo <= 100)
            cout << tempo << " anos." << endl;
        else
            cout << "Mais de 1 seculo." << endl;
    }
 
    return 0;
}