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

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

/// @brief Calcula se é possivel encontar a soma de subconjutos
/// @param p vetor de pesos
/// @param c alvo
/// @return 1 se for possivel encontrar, 0 se não for
bool subsetSum(const vtr &p, const int c) {
    int n = p.size();
    if(c < 0) return false;

    vector t(n + 1, vector<char>(c + 1, false));
    
    for(auto &i : t) i[0] = true;

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
    int v, m; cin >> v >> m;
    vtr moedas(m);
    for(int &i : moedas) cin >> i;

    if(subsetSum(moedas, v)) cout << 'S' << endl;
    else cout << 'N' << endl;

    return 0;
}
