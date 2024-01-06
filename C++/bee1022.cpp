#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

struct frac {
    int n, d;
};

void print(frac f) {
    cout << f.n << '/' << f.d << endl;
}

int main() {
    int n, mdc;
    char op, dct;
    frac f1, f2;

    cin >> n;

    while (n) {
        cin >> f1.n >> dct >> f1.d >> op >> f2.n >> dct >> f2.d;

        frac r, s;

        switch (op) {
        case '+':
            r = {f1.n * f2.d + f2.n * f1.d, f1.d * f2.d};
            break;
        case '-':
            r = {f1.n * f2.d - f2.n * f1.d, f1.d * f2.d};
            break;
        case '*':
            r = {f1.n * f2.n, f1.d * f2.d};
            break;
        default:
            r = {f1.n * f2.d, f1.d * f2.n};
            break;
        }

        mdc = gcd(r.n, r.d);
        s = {r.n / mdc, r.d / mdc};

        cout << r.n << '/' << r.d << " = " << s.n << '/' << s.d << endl;

        n--;
    }
    


    return 0;
}
