#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
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
const int TAM = 100+1;

class Solution {
private:
    int t[TAM][TAM];

public:
    Solution() {
        memset(t, -1, sizeof t);
    }

    int solve(const int n, const int W, vtr &pesos, vtr &valores) {
        if(t[n][W] != -1) return t[n][W];

        loop(i, 0, n+1) {
            loop(w, 0, W+1) {
                if(!i || !w) t[i][w] = 0;
                else if(pesos[i - 1] <= w)
                    t[i][w] = max(t[i - 1][w], valores[i - 1] + t[i - 1][w - pesos[i - 1]]);
                else t[i][w] = t[i - 1][w];
            }
        }

        return t[n][W];
    }
};

int main() {_
    while(1) {
        int n; cin >> n;
        if(!n) break;

        vtr precos(n), pesos(n);

        loop(i, 0, n) cin >> precos[i] >> pesos[i];

        int m; cin >> m;

        Solution solution;
        cout << solution.solve(n, m, pesos, precos) << endl;
    }


    return 0;
}
