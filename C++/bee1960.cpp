#include <bits/stdc++.h>

#define endl '\n'
#define f first
#define s second

using namespace std;


int main() {
    pair<int, string> rmn[] = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

    int n, x{0};
    cin >> n;

    for(int i{0}; i < 13; i++) {
        for(x = n / rmn[i].f; x; x--) cout << rmn[i].s;

        n %= rmn[i].f;
    }

    cout << endl;
}