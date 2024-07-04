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
typedef vector<vtr> gph;
typedef pair<int,int> par;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void dfs(int i, gph &g, vtr &vis) {
    vis[i] = 1;

    for(int v : g[i]) if(!vis[v]) dfs(v, g, vis);
}

int main() {_
    int n, m; cin >> n >> m;
    gph g(n);
    vtr vis(n, 0);

    loop(i, 0, m) {
        int a, b; cin >> a >> b; --a; --b;
        g[a].pb(b); g[b].pb(a);
    }

    uint cont{0};
    loop(i, 0, n) if(!vis[i]) {
        dfs(i, g, vis);
        cont++;
    }

    cout << cont << endl;

    return 0;
}
