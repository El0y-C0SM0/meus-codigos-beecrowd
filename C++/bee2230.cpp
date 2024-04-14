#include <bits/stdc++.h>

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define dbg(a) (cout << '\n' << #a << " = " << a << '\n')
#define loop(a,m) for(int i = a; i < m; ++i)
#define pb push_back
#define ins insert
#define f first
#define s second

using namespace std;

typedef uint32_t uint;
typedef long long ll;
typedef long double ld;
typedef vector<int> vtr;
typedef vector<vtr> gph;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

gph cid;
set<int> vis;
queue<pair<int, int>> q;
int p, l;

void bfs() {

    if(!p) return;

    for(int i : cid[l]) {
        q.push({i, 1});
        vis.ins(i);
    }

    while (!q.empty()) {
        auto x = q.front();  q.pop();
        if(x.s >= p) return;

        for(int i : cid[x.f]) if(!vis.count(i)) {
            q.push({i, x.s + 1});
            vis.ins(i);
        }
    }
    
}

int main() {_
    int cont{1};

    while(1) {
        int c, e;
        cin >> c >> e >> l >> p;
        if((!c && !e) && (!l && !p)) break;
        l--;
        
        cid = gph(c);
        vis.clear();
        q = queue<pair<int, int>>();

        loop(0, e) {
            int x, y;
            cin >> x >> y; x--; y--;

            cid[x].pb(y);
            cid[y].pb(x);
        }

        bfs();
        if(vis.count(l)) vis.erase(l);

        cout << "Teste " << cont++ << endl;
        for(int i : vis) {
            cout << i + 1 << ' ';
        }
        cout << endl << endl;
        
    }

    return 0;
}
