#include <bits/stdc++.h>
 
using namespace std;

#define endl '\n'

int simula(int n, int m) {
    int x{0};

    for(int i{1}; i < n; i++)
        x = (x + m) % i;

    return x;
}

int main() {
    int n;

    while(1) {
        cin >> n;
        if(!n) break;

        int m{1};

        while(1) {
            if(simula(n, m) != 11) m++;
            else break;
        }

        cout << m << endl;
    }
}