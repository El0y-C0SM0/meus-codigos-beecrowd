#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    vector<int> pes_direitos = vector<int>(31, 0);
    vector<int> pes_esquerdos = vector<int>(31, 0);
} Botas;

int main() {
    int num_botas = 0;
    while(cin >> num_botas){
        Botas botas;
        int cont_pares = 0;

        for(int i = 0; i < num_botas; i++) {
            int tam_pe;
            char pe;

            cin >> tam_pe >> pe;

            if(pe == 'E')
                botas.pes_esquerdos[tam_pe - 30]++;
            else
                botas.pes_direitos[tam_pe - 30]++;
        }

        for(int i = 0; i < 31; i++) {
            if(botas.pes_esquerdos[i] <= botas.pes_direitos[i])
                cont_pares += botas.pes_esquerdos[i];
            else
                cont_pares += botas.pes_direitos[i];
        }

        cout << cont_pares << endl;
    }

    return 0;
}