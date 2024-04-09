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
    uint i{1};

    while(1) {
        int m, n;
        cin >> m >> n;
        if(!m && !n) break;
        
        vtr med;

        loop(0, m) {
            int x; cin >> x;
            med.pb(x);
        }
        med.pb(0);

        pair<int, int> out = {INF, -INF};
        int x{0}, aux{n};
        for(int i{0}; i <= m; i++) {
            if(aux) 
                aux--;
            else {
                out.f = x / n < out.f ? x / n : out.f; 
                out.s = x / n > out.s ? x / n : out.s; 

                x -= med[i - n];
            }
            x += med[i];
        }

        cout << "Teste " << i++ << endl;
        cout << out.f << ' ' << out.s << endl << endl;
    }

    return 0;
}
