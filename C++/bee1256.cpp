#include <iostream>
#include <vector>

using namespace std;

class TabelaHash {
    private:
    unsigned int tamanho;
    vector<vector<int>> tabela;

    int faz_hash(int valor) {
        return valor % tamanho;
    }

    public:
    TabelaHash(int tam_tabela) : tamanho(tam_tabela) {
        tabela = vector<vector<int>>(tamanho);
    } 

    vector<int> get_elementos(unsigned int chave) {
        return tabela[chave];
    }

    void set_elemento(int valor) {
        tabela[faz_hash(valor)].push_back(valor);
    }
};

int main() {
    int num_casos = 0;

    cin >> num_casos;

    for(int i = 0; i < num_casos; i++) {
        int tamanho_tabela, num_inputs;

        cin >> tamanho_tabela >> num_inputs;

        TabelaHash tabela(tamanho_tabela);

        for(int j = 0; j < num_inputs; j++) {
            int input;
            cin >> input;
            tabela.set_elemento(input);
        }

        for(int j = 0; j < tamanho_tabela; j++) {
            vector<int> elementos = tabela.get_elementos(j);

            cout << j << " -> ";
            for(int elemento : elementos)
                cout << elemento << " -> ";
            cout << "\\" << endl;
        }

        if(i != num_casos - 1)
            cout << endl;
    }

    return 0;
}