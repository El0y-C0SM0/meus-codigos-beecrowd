#include <bits/stdc++.h>

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(NULL);
#define pb push_back
#define f first
#define s second

using namespace std;

typedef vector<int> vtr;
typedef pair<int,int> par;

int vis[9][9];
vector<par> movs{{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}};

bool isValid(par p) {
    return p.f > 0 && p.f <= 8 && p.s > 0 && p.s <= 8;
}

int bfs(par &ini, par &fim) {
    queue<par> q;
    q.push(ini);
    vis[ini.f][ini.s] = 1;

    while(!q.empty()) {
        par p = q.front(); q.pop();

        if(p == fim) return vis[p.f][p.s];

        for(auto i : movs) {
            i = {p.f + i.f, p.s + i.s};
            if(isValid(i)) {
                q.push(i);
                vis[i.f][i.s] = vis[p.f][p.s] + 1;
            } 
        }
    }

    return -1;
}

int main() {_
    string inicio, final;

    while (cin >> inicio >> final) {
        memset(vis, 0, sizeof vis);

        par ini{inicio[0] - 96, inicio[1] - 48};
        par fim{final[0] - 96, final[1] - 48};

        cout << "To get from " << inicio << " to " << final << " takes " << bfs(ini, fim) - 1 << " knight moves." << endl;
    }
    

}