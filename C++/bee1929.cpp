#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;

bool compara(int a, int b) {
    return a < b;
}
 
int main() {
    vector<int> medidas(4);

    cin >> medidas[0] >> medidas[1] >> medidas[2] >> medidas[3];

    sort(medidas.begin(), medidas.end(), compara);

    if(medidas[0] + medidas[1] > medidas[2] || medidas[1] + medidas[2] > medidas[3])
        cout << 'S' << endl;
    else
        cout << 'N' << endl;

    return 0;
}