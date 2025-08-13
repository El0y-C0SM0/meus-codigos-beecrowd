#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(a) (cout << #a << " = " << a << '\n')
#define loop(i,a,m) for(int i = a; i < m; ++i)
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

uint mdc(uint a, uint b) {
    for (uint r {a % b}; r; a = b, b = r, r = a % b);
    return b;
}

int main() {_
    uint ca, cp, e;

    while (cin >> ca >> cp >> e) {
        uint n = mdc(ca, cp);

        if (e <= (ca / n + cp / n)) cout << "sim" << endl;
        else cout << "nao" << endl;
    }

    return 0;
}
