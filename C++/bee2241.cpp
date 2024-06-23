#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define dbg(a) (cout << #a << " = " << a << '\n')
#define loop(i,a,m) for(int i = a; i < m; ++i)
#define pb push_back
#define f first
#define s second
#define P 1
#define B 2
#define E 3

using namespace std;

typedef uint32_t uint;
typedef long long ll;
typedef long double ld;
typedef vector<int> vtr;
typedef pair<int,int> par;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int tab[502][502], dp[502][502];

int corVizinhos(int i, int j) {
    if(tab[i][j] == tab[i+1][j] && tab[i][j] == tab[i][j+1] && tab[i][j] == tab[i+1][j+1])
        return tab[i][j];
    return E;
}

void simula(int n, int &p, int &b) {
    if(n == 2) return;

    auto vizinhosDiferentes = [&](int i, int j, int x){
        return tab[i+1][j] != x && tab[i][j+1] != x && tab[i+1][j+1] != x;
    };
 
    auto vizinhosIguais = [&](int i, int j, int x){
        return tab[i+1][j] == x || tab[i][j+1] == x || tab[i+1][j+1] == x;
    };
 
    for(int k{n}; k > 2; k--) {
        loop(i, 1, k) loop(j, 1, k) {
            if(tab[i][j] == E || vizinhosIguais(i, j, E))
                tab[i][j] = E;
            else if(tab[i][j] == P) {
                if(vizinhosDiferentes(i, j, B)) {
                    p++; tab[i][j] = P;
                } else {
                    tab[i][j] = E;
                }
            } else if(tab[i][j] == B) {
                if(vizinhosDiferentes(i, j, P)) {
                    b++; tab[i][j] = B;
                } else {
                    tab[i][j] = E;
                } 
            } else if(vizinhosIguais(i, j, P) && vizinhosDiferentes(i, j, B)) {
                p++; tab[i][j] = P;
            } else if(vizinhosIguais(i, j, B) && vizinhosDiferentes(i, j, P)) {
                b++; tab[i][j] = B;
            } else if(vizinhosIguais(i, j, P) && vizinhosIguais(i, j, B)) {
                tab[i][j] = E;
            }
        }
    }
}

int main() {_
    int n, p; cin >> n >> p;
    memset(tab, 0, sizeof tab);

    loop(i, 0, p) {
        int x, y; cin >> x >> y;
        tab[x][y] = P;
    }
 
    loop(i, 0, p) {
        int x, y; cin >> x >> y;
        tab[x][y] = B;
    }

    int pretas{p}, brancas{p};

    simula(n, pretas, brancas);

    cout << pretas << ' ' << brancas << endl;
 
    return 0;
}
