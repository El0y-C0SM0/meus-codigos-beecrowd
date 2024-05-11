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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vtr> g;
vtr to;

bool kahn(vector<vector<int>> &g, vector<int> &graus, vector<int> &vis) {
    priority_queue<int, vector<int>, greater<int>> q;

    for(int i{0}; i < (int) g.size(); i++) if(!graus[i]) q.push(i);

    while(!q.empty()) {
        int x = q.top(); q.pop();
        to.push_back(x);
        vis[x] = 1;
        
        for(int i : g[x]) if(!vis[i] && --graus[i]== 0)
            q.push(i);
    }

    return to.size() == g.size();
}

int main() {_
    int n, m; cin >> n >> m;

    vector<int> graus(n, 0), vis(n, 0);
    vector<vtr> g(n);
    

    loop(0, m) {
        int x, y; cin >> x >> y;

        graus[y]++;
        g[x].pb(y);

    }

    if(kahn(g, graus, vis))
        for(int i : to) cout << i << endl;
    else 
        cout << '*' << endl;

    return 0;
}
