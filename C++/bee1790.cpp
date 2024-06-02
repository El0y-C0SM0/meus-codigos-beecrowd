#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define dbg(a) (cout << #a << " = " << a << '\n')
#define loop(a,m) for(int i = a; i < m; ++i)
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

int low[50], depth[50];
int pontes;

void dfs(int i, int o, int d, gph &g) {
    low[i] = depth[i] = d++;

    for(int v : g[i]) {
        if(depth[v] < 0) {
            dfs(v, i, d, g);

            if(low[v] > depth[i]) pontes++;

            low[i] = min(low[i], low[v]);
        } else if(v != o) 
            low[i] = min(low[i], depth[v]);
    }
}

int main() {_
    int c, p;

    while(cin >> c >> p) {
        gph g(c);
        memset(low, 0, sizeof low);
        memset(depth, -1, sizeof depth);
        pontes = 0;

        loop(0, p) {
            int a, b; cin >> a >> b; a--; b--;
            g[a].pb(b);
            g[b].pb(a);
        }

        dfs(0, 0, 0, g);

        cout << pontes << endl;
    }

    return 0;
}
