#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef unsigned int uint;

uint josephus(uint n, uint k) {
    uint x{0};

    for(uint i{1}; i <= n; i++)
        x = (x + k) % i;

    return ++x;
}

int main() {
    int casos;
    cin >> casos;

    for(int i{0}; i < casos; i++) {
        uint m, n;
        cin >> n >> m;

        uint x{josephus(n, m)};

        cout << "Case " << i + 1 << ": " << x << endl;
    }

    return 0;
}