#include <bits/stdc++.h>

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define pb push_back
#define dbg(a) (cout << #a << " = " << a << '\n')
#define loop(i,m) for(int i = 0; i < m; ++i)
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
    uint c, n;
    char o = 'S';

    cin >> n >> c; n--;

    while(n--) {
        uint x; cin >> x;

        if(x > c) o = 'N';
    }

    cout << o << endl;

    return 0;
}
