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
typedef vector<uint> vtr;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

vtr max(vector<vtr> &als) {
    for(int i{100}; i >= 0; i--) {
        if(als[i].size() > 0)
            return als[i];
    }

    return vtr();
}

int main() {
    uint i{1};

    while(1) {
        ushort n;
        cin >> n; if(!n) break;

        vector<vtr> als(101);

        loop(0, n) {
            pair<ushort, ushort> a;
            cin >> a.f >> a.s;

            als[a.s].pb(a.f);
        }

        auto print = [&](){
            vtr m = max(als);

            for(auto &i : m) cout << i << ' ';
            cout << endl; 
        };

        cout << "Turma " << i++ << endl;
        print();
        cout << endl;
    }

    return 0;
}
