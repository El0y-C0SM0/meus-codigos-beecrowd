#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define dbg(a) (cout << #a << " = " << a << '\n')
#define loop(i,a,m) for(int i = a; i < m; ++i)
#define pb push_back

using namespace std;

typedef uint32_t uint;
typedef long long ll;
typedef long double ld;
typedef vector<int> vtr;
typedef pair<int,int> par;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Func {
    int idade;
    vtr enc;
};

vector<Func> lks;

bool dfs(int i, int x, vtr &s, vector<bool> &vis) {
    vis[i] = true;
    bool control{false};

    if(find(lks[i].enc.begin(), lks[i].enc.end(), x) != lks[i].enc.end()) 
        control = true;
    else {
        for(auto &j : lks[i].enc) {
            if((find(s.begin(), s.end(), j) != s.end()) || (!vis[j] && dfs(j, x, s, vis))) {
                control = true;
                break;
            }
        }
    }

    if(control) s.pb(i);
    
    return control;
}

void trocar(int a, int b) {
    loop(i, 0, lks.size()) {
        for(auto &j : lks[i].enc) {
            if(j == a) j = b;
            else if(j == b) j = a;
        }
    }

    swap(lks[a].enc, lks[b].enc);
}

int main() {_
    int empregados, gerencias, instrucoes;

    while(cin >> empregados >> gerencias >> instrucoes) {

        loop(i, 0, empregados) {
            int idade; 
            cin >> idade;

            Func f;
            f.idade = idade;
            lks.pb(f);
        }

        loop(i, 0, gerencias) {
            int x, y;
            cin >> x >> y; x--; y--;
            lks[x].enc.pb(y);
        }

        loop(i, 0, instrucoes) {
            char instrucao;
            cin >> instrucao;

            if(instrucao == 'T') {
                int a, b;
                cin >> a >> b; a--; b--;
                trocar(a, b);
            } else {
                int e;
                cin >> e; e--;

                vtr superiores;
                vector<bool> vis(lks.size(), false);

                auto menor_idade = [&](){
                    int idade{INF};

                    for(auto i : superiores)
                        idade = min(idade, lks[i].idade);

                    return idade;
                };

                loop(j, 0, empregados) if(!vis[j]) {
                    dfs(j, e, superiores, vis);
                }

                if(superiores.size()) cout << menor_idade() << endl;
                else cout << '*' << endl;
            }
        }

        lks.clear();
    }

    return 0;
}
