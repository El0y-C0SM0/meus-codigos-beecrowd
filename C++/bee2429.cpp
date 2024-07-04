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

int bfs(int i, vtr &g) {
    queue<int> q; q.push(i);
    vtr vis(g.size(), 0);
    int cont{0};

    while(!q.empty()) {
        int v{q.front()}; q.pop();
        cont++;
        vis[v] = 1;

        if(!vis[g[v]]) q.push(g[v]);
        else break;
    }

    return cont;
}

int main() {_
    int n; cin >> n;
    vtr cidades(n, 0);
    unordered_set<int> entradas, saidas;
    char resp{'S'};

    loop(i, 0, n) {
        int a, b; cin >> a >> b;

        if(cidades[a - 1]) {
            resp = 'N';
            continue;
        }
        
        cidades[a - 1] = b - 1;
        saidas.insert(a - 1); entradas.insert(b - 1);
    }

    if(entradas.size() != n || saidas.size() != n) resp = 'N';

    if(resp == 'S' && bfs(0, cidades) != n) resp = 'N';

    cout << resp << endl;

    return 0;
}
