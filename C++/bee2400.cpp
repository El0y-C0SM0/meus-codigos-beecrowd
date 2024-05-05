#include <bits/stdc++.h>

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define dbg(a) (cout << '\n' << #a << " = " << a << '\n')
#define loop(a,m) for(int i = a; i < m; ++i)
#define pb push_back
#define f first
#define s second

using namespace std;

typedef uint32_t uint;
typedef long long ll;
typedef long double ld;
typedef vector<int> vtr;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct FenwickTree {
    vector<int> v;

    FenwickTree(unsigned int n) {
        n++;
        v = vector<int>(n, 0);
    }

    void insert(unsigned int i, int x) {
        while(i < v.size()) {
            v[i] += x;
            i += i & (-i);
        }
    }

    int sum(unsigned int i) {
        int x{0};

        while(i > 0) {
            x += v[i];
            i -= i & (-i);
        }

        return x;
    }

    int sum(unsigned int i, int j) {
        return sum(j) - sum(i - 1);
    }
};

int main() {
    int n, maior{-INF}, r{0}; cin >> n;
    FenwickTree bit(n);
    vtr v(n);

    loop(0, n) {
        cin >> v[i];
        maior = max(maior, v[i]);
    }

    loop(0, n) {
        bit.insert(v[i], 1);
        r += bit.sum(maior) - bit.sum(v[i]);
    }

    cout << r << endl;

    return 0;
}
