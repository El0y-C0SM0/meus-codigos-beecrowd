#include <bits/stdc++.h>

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define dbg(a) (cout << #a << " = " << a << '\n')
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
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {_
    int n, g;
    cin >> n >> g;
    vector<vtr> m(n, vtr(n, 0)), c(n + 2, vtr(n + 2));

    for(int i{0}; i < n; i++) {
        for(int j{0}; j < n; j++) {
            cin >> m[i][j];

            c[i+1][j+1] = c[i+1][j] + c[i][j+1] - c[i][j] + m[i][j];
        }
    }

    auto sum = [&](int k, int i, int j){
        int a = i + k - 1, b = j + k - 1;
        return c[a][b] - c[i-1][b] - c[a][j-1] + c[i-1][j-1];
    };

    int t{0};
    for(int k{-1}, flg{0}; (2 << k) <= n; k++) {
        int x = (k >= 0) ? 2 << k : 2 >> 1;

        for(int i{1}; i <= n; i += x) {
            for(int j{1}; j <= n; j += x) {
                if(sum(x, i, j) < g) {
                    flg = 1;
                    break;
                }
            }

            if(flg) {
                break;
            }
        } 

        if(!flg) {
            t = (n * n) / (x * x);
            break;
        } else flg = 0;
    }

    cout << t << endl;

    return 0;
}
