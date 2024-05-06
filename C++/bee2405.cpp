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

vector<par> pos{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
vector<vtr> tab;
uint cont{0};

void mapping(par &o) {
    tab[o.f][o.s] = 1;
    cont++;

    auto valid = [&](par &a){
        return a.f >= 0 && a.f < ((int) tab.size()) && a.s >= 0 && a.s < ((int) tab[0].size());
    };

    for(auto &i : pos) {
        par no = {o.f + i.f, o.s + i.s};

        if(valid(no) && !tab[no.f][no.s]) mapping(no);
    }
}

int main() {_
    par p;
    int n, m, k;
    cin >> n >> m >> p.f >> p.s >> k;
    p.f--; p.s--;

    tab = vector<vtr>(n, vtr(m, 0));

    loop(0, k) {
        par aux; cin >> aux.f >> aux.s;
        tab[aux.f - 1][aux.s - 1] = -1;
    }

    mapping(p);
    
    cout << cont << endl;

    return 0;
}
