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
typedef vector<vtr> gph;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
    
gph als;
int n;


int search(int i, int tot, vtr excl) {
    if(i >= n) return tot;
    else if(excl[i]) return search(i + 1, tot, excl);

    excl[i] = 1;
    int x = search(i + 1, tot, excl);
    
    excl[i] = 0;
    for(int j : als[i]) excl[j] = 1;
    int y = search(i + 1, tot + 1, excl);

    return max(x, y);
}

int main() {
    uint teste{1};

    while (1) {
        cin >> n;
        if(!n) break;

        vtr excl(n, 0);
        als = gph(n);

        loop(0, n) {
            excl[i] = 0;
            while (1) {
                int x; cin >> x;
                if(!x) break;
                als[x - 1].pb(i); als[i].pb(x - 1);
            }
        }
        

        cout << "Teste " << teste++ << endl;
        cout << search(0, 0, excl) << endl << endl;
    }

    return 0;
}
