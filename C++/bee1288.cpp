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
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vtr dtr, pso;
int t[60][110];

int dp(int i, int j) {
    if(j < 0) return -INF;
    if(i == dtr.size()) return 0;
    if(t[i][j] != -1) return t[i][j];

    return t[i][j] = max(dp(i + 1, j), dp(i + 1, j - pso[i]) + dtr[i]);
}

int main() {_
    int teste; cin >> teste;

    while(teste--) {
        int n; cin >> n;

        dtr = vtr(n); pso = vtr(n);
        memset(t, -1, sizeof t);

        loop(0, n) cin >> dtr[i] >> pso[i];

        int k; cin >> k;
        int r; cin >> r;

        if(dp(0, k) >= r) cout << "Missao completada com sucesso" << endl;
        else cout << "Falha na missao" << endl;
    }

    return 0;
}
