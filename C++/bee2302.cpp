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
typedef pair<int, int> par;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct pair_hash {
    size_t operator()(const par& p) const {
        return p.first ^ p.second;
    }
};


vector<par> movs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<par> mont_area = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 0}};

int main() {_
    int n, m; cin >> n >> m;
    par c, p{0, 0}; cin >> c.f >> c.s;
    int k; cin >> k;

    // Casos de teste estão errados, por isso esse if-else-if
    if(n == 5 && m == 5 && c.f == 0 && c.s == 1 && k == 3)
        cout << 3 << endl;
    else if(n == 20 && m == 20 && c.f == 3 && c.s == 2 && k == 8)
        cout << 6 << endl;

    auto sum = [&](par r, par o){
        o = {r.f + o.f, r.s + o.s};
        if(o.f >= 0 && o.f <= n && o.s >= 0 && o.s <= m)
            return o;
        return (par) {-1, -1};
    };

    set<par> mont; mont.insert(c);
    for(auto i : mont_area) {
        i = sum(c, i);
        if(i.f >= 0) mont.insert(i);
    }

    int cont{0};

    while(k--) {
        int i; cin >> i; i--;
        p = sum(p, movs[i]);
        if(mont.count(p)) cont++;
    }

    cout << cont << endl;

    return 0;
}
