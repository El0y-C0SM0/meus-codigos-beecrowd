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
const int TAM = 1000;

unordered_map<string, int> guns{
    {"HANDGUN", 20},
    {"RED9", 35},
    {"BLACKTAIL", 35},
    {"MATILDA", 20},
    {"HANDCANNON", 600},
    {"STRIKER", 120},
    {"TMP", 12},
    {"RIFLE", 120} 
};

unordered_map<string, int> monsters{
    {"GANADOS", 500},
    {"COBRAS", 400},
    {"ZEALOT", 750},
    {"COLMILLOS", 600},
    {"GARRADOR", 1250},
    {"LASPLAGAS", 1000},
    {"GATLINGMAN", 1500},
    {"REGENERATOR", 2500},
    {"ELGIGANTE", 5000},
    {"DR.SALVADOR", 3500},
};

class Solution {
private:
    int t[TAM][TAM];
    int peso_max;

    int knapsack(const int n, const int W, vtr &pesos, vtr &valores) {
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

public:
    Solution() {
        memset(t, -1, sizeof t);
    }

    bool solve(const int h, const int n, const int W, vtr &pesos, vtr &valores) {
        return h <= knapsack(n, W, pesos, valores);
    }
};

int main() {_
    int qa, qm, qb;

    while(cin >> qa) {
        vtr municoes(qa);
        vtr danos(qa);

        loop(i, 0, qa) {
            string nome;
            int balas;
            cin >> nome >> balas;
            municoes[i] = balas;
            danos[i] = guns[nome] * balas;
        }

        int vida{0};
        cin >> qm;

        loop(i, 0, qm) {
            string nome;
            int qnt;
            cin >> nome >> qnt;
            vida += monsters[nome] * qnt;
        }

        cin >> qb;

        Solution solution;
        cout << (solution.solve(vida, qa, qb, municoes, danos) ? "Missao completada com sucesso" : "You Are Dead") << endl << endl;
    }

    return 0;
}
