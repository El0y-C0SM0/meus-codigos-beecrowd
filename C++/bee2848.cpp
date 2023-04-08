#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
 
using namespace std;

vector<int> ordena(vector<int> &vtr, const int ini, const int fim) {
    int tam = fim - ini;
    vector<int> vtr_copia(tam);

    for(int i = 0, j = ini; i < tam; i++, j++)
        vtr_copia[i] = vtr[j];

    for(int i = 1; i < tam; i++) {
        int x = vtr_copia[i];
        int j = i - 1;

        while(j >= 0 && vtr_copia[j] > x) {
            vtr_copia[j + 1] = vtr_copia[j];
            j--;
        }

        vtr_copia[j + 1] = x;
    }

    return vtr_copia;
}

int main() {
    int tam, rodadas;
    cin >> tam >> rodadas;

    vector<int> vtr(tam);

    for(int i = 0; i < tam; i++)
        cin >> vtr[i];

    while (rodadas) {
        int intervalo[2], k, palpite_g, palpite_d, cont;

        cin >> intervalo[0] >> intervalo[1] >> k >> palpite_g >> palpite_d;

        intervalo[0]--;
        k--;

        vector<int> vtr_copia = ordena(vtr, intervalo[0], intervalo[1]);

        cont = count(vtr_copia.begin(), vtr_copia.end(), vtr_copia[k]);

        if(abs(cont - palpite_g) < abs(cont - palpite_d))
            cout << vtr_copia[k] << " " << cont << " G" << endl;
        else if(abs(cont - palpite_d) < abs(cont - palpite_g))
            cout << vtr_copia[k] << " " << cont << " D" << endl;
        else
            cout << vtr_copia[k] << " " << cont << " E" << endl;

        rodadas--;
    }
    

    return 0;
}