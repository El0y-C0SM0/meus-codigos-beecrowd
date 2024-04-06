#include <bits/stdc++.h>

#define endl '\n'
#define dbg(a) (cout << '\n' << #a << " = " << a << '\n')
#define SIZE 3501

using namespace std;

typedef unsigned int uint;

uint primes[SIZE] = {}; 

int is_prime(uint n) {
    uint cont{0};

    for(uint i{2}; i <= sqrt(n); i++) {
        if(n % i == 0) {
            cont++;
            break;
        } 
    }

    return cont == 0;
}

void fill_primes() {
    uint x{0};

    for(uint i{2}; x < SIZE; i++) {
        if(is_prime(i)) {
            primes[x] = i;
            x++;
        }
    }
}

uint josephus(uint n) {
    uint x{0};

    for(uint i{1}; i <= n; i++) {
        x = (x + primes[n - i]) % i;
    }

    return x;
}

int main() {
    uint n;

    fill_primes();

    while (1) {
        cin >> n;
        if(!n) break;

        uint x{josephus(n)};

        cout << x + 1 << endl;
    }

    return 0;
}