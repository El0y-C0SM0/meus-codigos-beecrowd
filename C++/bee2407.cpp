// ! time limit
#include <bits/stdc++.h>

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define dbg(a) (cout << '\n' << #a << " = " << a << '\n')
#define loop(a,n) for(int i = a; i < n; ++i)
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

int main() { _
    vector<vtr> quad;
    set<int> cont;
    int n, flg{0};
    cin >> n;

    for(int i{0}; i < n; i++) {
        vtr x;

        for(int j{0}; j < n; j++) {
            int y; cin >> y;
            x.pb(y);
            cont.insert(y);
        }

        quad.pb(x);
    }

    if(cont.size() != n * n) {
        cout << 0 << endl;
        return 0;
    }

    int x, z{0};
    for(int i{0}, w{0}, y{0}; i < n; i++, y = 0, w = 0) {
        for(int j{0}; j < n; j++) {
            y += quad[i][j];
            w += quad[j][i];
        }

        z += quad[i][i];

        if(i == 0) x = y;
        if(x != y || x != w) {
            cout << 0 << endl;
            return 0;
        }
    }

    if(x != z) {
        cout << 0 << endl;
        return 0;
    }

    cout << x << endl;

    return 0;
}