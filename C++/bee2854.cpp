#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
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
typedef vector<uint> vtr;
typedef vector<vtr> gph;
typedef pair<int,int> par;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

unordered_map<string, uint> pessoas;

void dfs(gph &g, int i, vtr &vis) {
    vis[i] = 1;

    for (auto &v : g[i]) if (!vis[v]) dfs(g, v, vis);
}

int main() {_
    int m, n; cin >> m >> n;

    gph g(m);
    vtr vis(m, 0);

    auto exists = [&](string s){
        return (pessoas.find(s) != pessoas.end());
    };

    loop (i, 0, n) {
        string p1, r, p2; cin >> p1 >> r >> p2;

        if (!exists(p1))
            pessoas[p1] = pessoas.size();
        if (!exists(p2))
            pessoas[p2] = pessoas.size();

        g[pessoas[p1]].pb(pessoas[p2]);
        g[pessoas[p2]].pb(pessoas[p1]);
    }

    uint cont {0};
    loop (i, 0, m) if (!vis[i]) {
        dfs(g, i, vis);
        cont++;
    }

    cout << cont << endl;


    return 0;
}
