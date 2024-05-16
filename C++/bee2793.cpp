#include <bits/stdc++.h>

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define dbg(a) (cout << '\n' << #a << " = " << a << '\n')
#define loop(a,m) for(int i = a; i < m; ++i)
#define pb push_back

using namespace std;

typedef uint32_t uint;
typedef long long ll;
typedef long double ld;
typedef vector<int> vtr;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll P = 1e9+7;

ll mod_pow(ll x, ll y, ll mod) {
    ll res = 1;

    x %= mod;

    if(!x) return 0;

    while (y > 0) {
        if (y & 1) 
            res = (res * x) % mod;
        
        x = (x * x) % mod;
        y /= 2;
    }

    return res;
}

int main() {_
    ll cont{0}, x{0};
    string s; cin >> s;

    for(auto &r : s) {
        x += r == 'M' ? 1 : -1;

        if(!x) cont++;
    }

    cout << mod_pow(2, cont - 1, P) << endl;

    return 0;
}
