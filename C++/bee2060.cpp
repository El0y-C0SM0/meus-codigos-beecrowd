#include <iostream>

using namespace std;

int main() {
    int mult_2 = 0, mult_3 = 0, mult_4 = 0, mult_5 = 0;
    int quant;

    cin >> quant;

    for(int i = 0, aux; i < quant; i++) {
        cin >> aux;
        
        if(!(aux % 2))
            mult_2++;
        if(!(aux % 3))
            mult_3++;
        if(!(aux % 4))
            mult_4++;
        if(!(aux % 5))
            mult_5++;
    }

    cout << mult_2 << " Multiplo(s) de 2" << endl;
    cout << mult_3 << " Multiplo(s) de 3" << endl;
    cout << mult_4 << " Multiplo(s) de 4" << endl;
    cout << mult_5 << " Multiplo(s) de 5" << endl;
    
    return 0;
}