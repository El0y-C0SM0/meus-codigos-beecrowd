#include <bits\stdc++.h>

#define endl '\n'
#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() { sws;
    int num_bancos, num_debentures;
    while (1) {
        cin >> num_bancos >> num_debentures;

        if(!num_bancos && !num_debentures) break;

        vector<int> bancos;

        while(num_bancos--) {
            int aux; cin >> aux; bancos.push_back(aux);
        }

        while(num_debentures--) {
            int banco_p, banco_r, valor;
            cin >> banco_p >> banco_r >> valor;
            --banco_p; --banco_r;
            bancos[banco_p] -= valor;
            bancos[banco_r] += valor;
        }

        int controle {1};
        for(int i : bancos) {
            if(i < 0) controle = 0;
        }

        if(controle) cout << 'S' << endl;
        else cout << 'N' << endl;
    }

    return 0;
}
