#include <bits/stdc++.h>

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define dbg(a) (cout << '\n' << #a << " = " << a << '\n')
#define loop(a,m) for(int i = a; i < m; ++i)
#define pb push_back
#define f first
#define s second

using namespace std;

typedef unsigned long long ull;
typedef uint32_t uint;
typedef long long ll;
typedef long double ld;
typedef vector<int> vtr;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {_
    while(1) {
        int n, m;
        cin >> n >> m;
        if(n < 0) break;

        ull t{0};

        loop(0, n) {
            uint x; cin >> x;
            t += x * (n - i);
        }

        t *= m;

        cout << t << endl;
    }

    return 0;
}
