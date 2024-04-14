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
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main() {_
    int i{1};

    while(1) {
        int n;
        unordered_map<string, vtr> comp;

        cin >> n;
        if(!n) break;

        loop(0, n) {
            string nome;
            cin >> nome;

            comp[nome] = vtr(12);
            
            for(int j{0}; j < 12; j++) {
                int x; cin >> x;
                comp[nome][j] = x;
            }
        }

        auto sum = [](vtr &v){
            int x{0};

            loop(1, 11) x += v[i];

            return x; 
        };

        vector<pair<string, int>> rank;
        
        for(auto i : comp) {
            sort(i.s.begin(), i.s.end());

            rank.pb({i.f, sum(i.s)});
        }

        sort(rank.begin(), rank.end(), [](auto &a, auto &b) {
            return a.s > b.s || (a.s == b.s && a.f < b.f);
        });

        auto classif = [&](pair<string, int> &p){
            int j{1};

            for(auto i : rank) if(i.s > p.s)
                j++;
            else if (i.f == p.f) break;

            return j;
        };

        cout << "Teste " << i++ << endl;
        for(auto i : rank) cout << classif(i) << ' ' << i.s << ' ' << i.f << endl;
        cout << endl;
    }

    return 0;
}
