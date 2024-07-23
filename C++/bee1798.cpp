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

int knapsack(const int n, const int W, vtr &pesos, vtr &valores) {
    vector<vtr> t(n+1, vtr(W+1, -1));

    if(t[n][W] != -1) return t[n][W];

    loop(i, 0, n+1) {
        loop(w, 0, W+1) {
            if(!i || !w) t[i][w] = 0;
            else if(pesos[i - 1] <= w) {
                int n1 = t[i - 1][w];
                int n2 = valores[i - 1] + t[i - 1][w - pesos[i - 1]];
                int n3 = valores[i - 1] + t[i][w - pesos[i - 1]];
                t[i][w] = max({n1, n2, n3});
            } else t[i][w] = t[i - 1][w];
        }
    }

    return t[n][W];
}
int main() {_
    int n, t; cin >> n >> t;
    vtr tamanhos(n), valores(n);

    loop(i, 0, n) cin >> tamanhos[i] >> valores[i];

    cout << knapsack(n, t, tamanhos, valores) << endl;

    return 0;
}
