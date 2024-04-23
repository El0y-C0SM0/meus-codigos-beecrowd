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

bool subset_sum(const vector<int> &p, const int c) {
    int n = p.size();
    if(n == 0 || c < 0) return false;

    vector t(n + 1, vector<char>(c + 1, false));
    
    for(auto &i : t) {
        i[0] = true;
    }

    for(int i{1}; i <= n; i++) {
        for(int j{1}; j <= c; j++) {
            int b = t[i - 1][j];

            if(j >= p[i - 1]) b = t[i - 1][j] || t[i - 1][j - p[i - 1]];
    
            t[i][j] = b;
        }
    }

    return t[n][c];
}

int main() {_
    int x, y, n, teste{1};

    while (1) {
        cin >> x >> y >> n;
        if(!x && !y && !n) break;

        vtr t(n);
        int total{0};

        loop(0, n) {
            cin >> t[i];
            total += t[i];
        }

        int a = total + x + y;

        if(a % 2 != 0) {
            cout << "Teste " << teste++ << endl << 'N' << endl << endl;
            continue;
        }

        cout << "Teste " << teste++ << endl;
        cout << (subset_sum(t, a / 2 - x) ? 'S' : 'N') << endl << endl;
    }

    return 0;
}
