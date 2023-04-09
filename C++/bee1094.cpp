#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int num_casos;
    int quant_cobaias = 0, quant_coelhos = 0, quant_ratos = 0, quant_sapos = 0;

    cin >> num_casos;

    for(int i = 0; i < num_casos; i++) {
        int quant;
        char cobaia;

        cin >> quant >> cobaia;

        quant_cobaias += quant;

        switch (cobaia) {
        case 'C':
            quant_coelhos += quant;
            break;
        case 'R':
            quant_ratos += quant;
            break;
        case 'S':
            quant_sapos += quant;
            break;
        }
    }

    cout << fixed << setprecision(2);
    cout << "Total: " << quant_cobaias << " cobaias" << endl;
    cout << "Total de coelhos: " << quant_coelhos << endl;
    cout << "Total de ratos: " << quant_ratos << endl;
    cout << "Total de sapos: " << quant_sapos << endl;
    cout << "Percentual de coelhos: " << (quant_coelhos * 100.0) / quant_cobaias << " %" << endl;
    cout << "Percentual de ratos: " << (quant_ratos * 100.0) / quant_cobaias << " %" << endl;
    cout << "Percentual de sapos: " << (quant_sapos * 100.0) / quant_cobaias << " %" << endl;

    return 0;
}