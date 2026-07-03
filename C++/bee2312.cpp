#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(a) (cout << #a << " = " << a << '\n')
#define loop(i,a,m) for (int i = a; i < m; ++i)
#define pb push_back
#define f first
#define s second

using namespace std;

typedef uint32_t uint;
typedef long long ll;
typedef long double ld;
typedef vector<int> vtr;
typedef pair<int,int> par;

typedef tuple<uint, uint, uint, string> pais;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {_
    uint n; cin >> n;

    vector<pais> paises;
    
    loop(i, 0, n) {
        uint o, p, b;
        string pa;
        cin >> pa >> o >> p >> b;
        paises.pb({o, p, b, pa});
    }

    sort(paises.begin(), paises.end(), [](pais &x, pais &y){
        uint ox = get<0>(x), px = get<1>(x), bx = get<2>(x);
        uint oy = get<0>(y), py = get<1>(y), by = get<2>(y);
        string pais_x = get<3>(x), pais_y = get<3>(y);

        if (ox > oy) return 1;
        else if (px > py && ox == oy) return 1;
        else if (bx > by && px - py + ox - oy == 0) return 1;
        else if (pais_x <= pais_y && ox - oy + px - py + bx - by == 0) return 1;
        
        return 0;
    });

    for (auto &[o, p, b, pa] : paises) {
        cout << pa << ' ' << o << ' ' << p << ' ' << b << endl;
    }

    return 0;
}
