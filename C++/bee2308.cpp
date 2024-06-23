#include <bits/stdc++.h>

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
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
typedef vector<vector<par>> gph;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int dijkstra(int i, gph &g) {
    priority_queue<par> q; q.push({0, i});
    vtr vis(g.size(), 0);
    int path{INF};

    while (!q.empty()) {
        par p = q.top(); q.pop();
        vis[p.s] = 1;

        for(auto &v : g[p.s]) {
            if(v.s == i) path = min(path, -(p.f - v.f));

            if(!vis[v.s]) q.push({p.f - v.f, v.s});
        }
    }

    return path;
}

int main() {_
    int s, c; cin >> s >> c;
    vtr tempos(s);
    gph salas(s);
    loop(i, 0, s) cin >> tempos[i];

    loop(i, 0, c) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        salas[a].pb({c + tempos[a], b});
    }

    int r{INF};
    loop(i, 0, s) r = min(r, dijkstra(i, salas));

    cout << r << endl;

    return 0;
}
