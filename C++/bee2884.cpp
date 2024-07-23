#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define dbg(a) (cout << #a << " = " << a << '\n')
#define loop(i,a,m) for(uint i = a; i < m; ++i)
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
const uint LIM = 2000;

int solve(unordered_set<uint> &acesas, vector<vtr> &interruptores) {
    uint cont{0};
    
    while(cont < LIM) {
        for(auto &i : interruptores) {
            cont++;

            for(auto &j : i) {
                if(acesas.count(j)) acesas.erase(j);
                else acesas.insert(j);
            }

            if(acesas.empty()) return cont;
        }
    }

    return -1;
}

int main() {_
    uint n, m; cin >> n >> m;

    uint l; cin >> l;
    unordered_set<uint> acesas;
    loop(i, 0, l) {
        uint x; cin >> x; acesas.insert(x);
    }

    vector<vtr> interruptores(n);
    for(auto &i : interruptores) {
        uint k; cin >> k;
        loop(j, 0, k) {
            int x; cin >> x; i.pb(x);
        }
    }

    cout << solve(acesas, interruptores) << endl;

    return 0;
}
