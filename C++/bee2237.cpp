#include <bits/stdc++.h>

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
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
typedef pair<int, vtr> stt;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct hasher {
    int operator()(const vector<int> &V) const {
        int hash = V.size();
        
        for(int i{0}; i < 8; i++) {
            hash ^= V[i] * 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }

        return hash;
    }
};

vector<par> movs{{0, 4}, {0, 1}, {4, 5}, {1, 5}, {1, 2}, {5, 6}, {2, 6}, {2, 3}, {6, 7}, {3, 7}};
unordered_map<vtr, int, hasher> states;

int troca(par p, vtr &a, vtr &b) {
    copy(a.begin(), a.end(), b.begin());

    b[p.f] = a[p.s];
    b[p.s] = a[p.f];

    return a[p.f] + a[p.s];
}

int dijkstra(vtr &v, vtr &dest) {
    priority_queue<stt> pq;
    pq.push({0, v});
    hasher hsh;

    while(!pq.empty()) {
        vtr u = pq.top().s;
        int d = -pq.top().f;
        pq.pop();

        if(states.count(u) && states[u] <= d) continue;
        states[u] = d;
 
        if(hsh(u) == hsh(dest)) 
            return d;

        vtr w(8);
        for(par i : movs) {
            int x = troca(i, u, w);

            if(!states.count(w) || states[w] > x + d)
                pq.push({-(x + d), w});
        }
    }

    return -1;
}

int main() {_
    vtr ini(8), fim(8);

    loop(0, 8) cin >> ini[i];
    loop(0, 8) cin >> fim[i];

    cout << dijkstra(ini, fim) << endl;

    return 0;
}
