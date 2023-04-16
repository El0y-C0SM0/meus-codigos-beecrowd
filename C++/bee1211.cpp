#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
 
using namespace std;

int acha_diferenca(string a, string b) {
    int i = 0;

    while(a[i] == b[i] && i < a.size())
        i++;

    return i;
}

int cont_caracteres(vector<string> telefones) {
    int cont = 0;

    for(int i = 0, j = 1; i < telefones.size() - 1; i++, j++) {
        cont += acha_diferenca(telefones[i], telefones[j]);
    }

    return cont;
}

bool compara(string a, string b) {
    return a < b;
}

int main() {
    int quant_nums;
    while (cin >> quant_nums) {
        vector<string> telefones;

        for(int i = 0; i < quant_nums; i++) {
            string aux;
            cin >> aux;
            telefones.push_back(aux);
        }

        sort(telefones.begin(), telefones.end(), compara);

        cout << cont_caracteres(telefones) << endl;
        
    }

    return 0;
}