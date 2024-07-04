#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define dbg(a) (cout << #a << " = " << a << '\n')
#define loop(i,a,m) for(int i = a; i < m; ++i)
#define pb push_back
#define f first
#define s second

using namespace std;

typedef uint32_t uint;
typedef long long ll;
typedef long double ld;
typedef vector<int> vtr;
typedef pair<int,int> par;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

class Ponto {
public:
    ll x, y;

    Ponto() : x(0), y(0) {}
};

inline ll distCentro(const Ponto &p) {
    return p.x * p.x + p.y * p.y;
}

ll solve(vector<ll> &circulos, vector<ll> &pontos) {
    ll cont{0};

    sort(pontos.begin(), pontos.end());
    for(auto &i : circulos) 
        cont += lower_bound(pontos.begin(), pontos.end(), i + 1) - pontos.begin();

    return cont;
}

int main() {_
    int c, t; cin >> c >> t;
    vector<ll> circulos(c);
    vector<ll> pontos(t);

    for(auto &i : circulos) {
        ll x; cin >> x;
        i = x * x;
    }

    Ponto p;
    for(auto &i : pontos) {
        cin >> p.x >> p.y;
        i = distCentro(p);
    }

    cout << solve(circulos, pontos) << endl;

    return 0;
}
