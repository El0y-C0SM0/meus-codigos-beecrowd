#include <bits/stdc++.h>

#define endl '\n'
#define pb push_back

using namespace std;

typedef vector<int> vi;

vi fib = {17711, 10946, 6765, 4181, 2584, 1597, 987, 610, 377, 233, 144, 89, 55, 34, 21, 13, 8, 5, 3, 2, 1, 0};

int main() {
    int n;
    cin >> n;

    while(n--) {
        int x, y{0};
        cin >> x;

        for(int i{0}; i < 21 && x; i++) if(fib[i] <= x) {
            x -= fib[i];
            y += fib[i + 1];
        }

        cout << y << endl;
    }

    return 0;
}