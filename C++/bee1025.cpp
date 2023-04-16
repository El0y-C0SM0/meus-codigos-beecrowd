#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'
#define uint unsigned int

using namespace std;

int main() {
    uint caso {1};
    
    while(1) {
        uint num_marmores, quant_consultas;

        cin >> num_marmores >> quant_consultas;
        if(!num_marmores && !quant_consultas)
            return 0;

        vector<int> marmores(num_marmores);

        for(int &i : marmores) {
            cin >> i;
        }

        auto compara = [](int a, int b)->bool{
            return a < b;
        };

        sort(marmores.begin(), marmores.end(), compara);

        cout << "CASE# " << caso << ':' << endl;
        for(uint i {0}; i < quant_consultas; ++i) {
            int x;
            cin >> x;

            auto pos = find(marmores.begin(), marmores.end(), x);

            if(pos != marmores.end()) 
                cout << x << " found at " << pos - marmores.begin() + 1 << endl;
            else
                cout << x << " not found" << endl;
        }

        ++caso;
    }
    
}
