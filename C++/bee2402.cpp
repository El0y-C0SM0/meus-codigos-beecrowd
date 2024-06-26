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

ll firstPrimeFactor(ll n) {
    if (!(n & 1))
        return 2;
    
    for (ll i{3}; i * i <= n; i += 2)
        if (!(n % i))
            return i;

    return n;
}

bool isPrime(ll n) {
    return n > 1 and firstPrimeFactor(n) == n;
}

int main() { _
    ll n; cin >> n;
    cout << (isPrime(n) or n == 1 ? "N" : "S") << endl;

    return 0;
}
