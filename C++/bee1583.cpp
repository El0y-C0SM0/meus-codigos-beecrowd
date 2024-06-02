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
typedef pair<int,int> par;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

char mapa[50][50];
queue<par> agt_t;
vector<par> movs{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool is_valid(par &p) {
    return p.f >= 0 && p.f < 50 && p.s >= 0 && p.s < 50 && mapa[p.f][p.s] == 'A';
}

void fluid_fill() {
    while(!agt_t.empty()) {
        par p = agt_t.front(); agt_t.pop();

        mapa[p.f][p.s] = 'T';

        for(par &i : movs) {
            par u{i.f + p.f, i.s + p.s};
            if(is_valid(u)) agt_t.push(u);
        }
    }
}

int main() {_
    while(1) {
        int n, m; cin >> n >> m;
        if(!n) return 0;

        memset(mapa, 0, sizeof mapa);

        for(int i{0}; i < n; i++) {
            for(int j{0}; j < m; j++) {
                cin >> mapa[i][j];
                if(mapa[i][j] == 'T') agt_t.push({i, j});
            }
        }

        fluid_fill();

        for(int i{0}; i < n; i++) {
            for(int j{0}; j < m; j++) cout << mapa[i][j];
            cout << endl;
        }
        cout << endl;

    }
    return 0;
}
