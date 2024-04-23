#include <bits/stdc++.h>

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define dbg(a) (cout << '\n' << #a << " = " << a << '\n')
#define loop(a,m) for(int i = a; i < m; ++i)
#define pb push_back
#define f first
#define s second
#define ROOT 0

using namespace std;

typedef uint32_t uint;
typedef long long ll;
typedef long double ld;
typedef vector<int> vtr;
typedef vector<vtr> gph;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

gph cpt;
vtr vis, depth, low;
set<int> aps;

void dfs(int x, int d) {
    vis[x] = 1;
    depth[x] = low[x] = d;
    int children{0};

    for(auto &i : cpt[x]) {
        if(depth[i] == depth[x] - 1) continue;

        if(vis[i]) {
            low[x] = min(low[x], depth[i]);
            continue;
        }

        dfs(i, d+1);
        low[x] = min(low[x], low[i]);
        if(low[i] >= depth[x] && x != ROOT) 
            aps.insert(x);
        children++;
    }

    if(x == ROOT && children > 1) aps.insert(x);
}

int main() {_
    int teste{1};

    while(1) {
        int n, m;
        cin >> n >> m;
        if(!n && !m) break;

        cpt = gph(n);
        vis = vtr(n, 0);
        depth = vtr(n, -1);
        low = vtr(n);
        aps = set<int>();

        loop(0, m) {
            int x, y; cin >> x >> y; x--; y--;

            cpt[x].pb(y);
            cpt[y].pb(x);
        }

        dfs(ROOT, 1);

        cout << "Teste " << teste++ << endl;
        if(aps.size()) for(int i : aps) cout << i + 1 << ' ';
        else cout << "nenhum";
        cout << endl << endl;

    }

    return 0;
}
