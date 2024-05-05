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

int main() {_
    int l, c, m, n;
    cin >> l >> c >> m >> n;
    vector t(l / m, vtr(c / n, 0));

    for(int i{0}; i < l; i++) {
        for(int j{0}; j < c; j++) {
            int x; cin >> x;
            t[i / m][j / n] += x; 
        }
    }

    int x{-1};
    for(auto &i : t) {
        for(auto &j : i) x = max(j, x);
    }
    cout << x << endl;

    return 0;
}
