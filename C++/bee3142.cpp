#include <iostream>
#include <string>

using namespace std;

int main() {
    string coluna;
    while (cin >> coluna) {
        int cont = coluna.length();
        int soma;

        if(cont == 1)
           soma = coluna[0] - 64;
        else if(cont == 2)
            soma = (coluna[0] - 64) * 26 + (coluna[1] - 64);
        else if(cont == 3)
            soma = 26 * ((coluna[0] - 64) * 26 + (coluna[1] - 64)) + (coluna[2] - 64);
        else
            soma = 100000;

        if(soma <= 16384)
            cout << soma << endl;
        else
            cout << "Essa coluna nao existe Tobias!" << endl;
    }

    return 0;
}