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

bool verificaSapo(const vector<pair<int, int>>& sapos, int i) {
    for (auto [pos, pulo] : sapos)
        if (abs(i - pos) % pulo == 0)
            return true;

    return false;
}

int main() { _
    uint n, m; cin >> n >> m;
    vector<pair<int, int>> sapos(m);

    for (auto& [pos, pulo] : sapos)
        cin >> pos >> pulo;

    for (int i {1}; i <= n; ++i) {
        cout << verificaSapo(sapos, i) << endl;
    }

    return 0;
}
