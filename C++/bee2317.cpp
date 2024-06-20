#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define dbg(a) (cout << #a << " = " << a << '\n')
#define loop(i,a,m) for(int i = a; i < m; ++i)
#define pb push_back
#define f first
#define s second
#define OVELHA 'k'
#define LOBO 'v'
#define CERCA '#'

using namespace std;

typedef uint32_t uint;
typedef long long ll;
typedef long double ld;
typedef vector<int> vtr;
typedef pair<int,int> par;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

class Solution {
private:
    vector<par> movs{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int ovelhas_pasto, lobos_pasto;
    queue<par> q; 

    bool is_valid(par a){
        return a.f >= 0 && a.f < r && 
            a.s >= 0 && a.s < c && 
            farm[a.f][a.s] && farm[a.f][a.s] != CERCA;
    };

    void count(int i, int j) {
        switch(farm[i][j]) {
        case OVELHA:
            ovelhas_pasto++;
            break;
        case LOBO:
            lobos_pasto++;
            break;
        }

        farm[i][j] = 0;

        for(auto &o : movs) if(is_valid({o.f + i, o.s + j})) 
            count(o.f + i, o.s + j);
    }
    
public:
    char farm[252][252];
    int r, c;
    int lobos, ovelhas;

    Solution(int r, int c) : r(r), c(c) {
        memset(farm, 0, sizeof farm);
        lobos = 0; ovelhas = 0;
    }

    void simula() {
        loop(i, 0, r) {
            loop(j, 0, c) if(is_valid({i, j})) {
                ovelhas_pasto = 0;
                lobos_pasto = 0;
                count(i, j);
                if(ovelhas_pasto > lobos_pasto)
                    ovelhas += ovelhas_pasto;
                else
                    lobos += lobos_pasto;
            }
        }
    }
};

int main() {
    int r, c;
    scanf("%d %d", &r, &c);
    Solution sol(r, c);

    loop(i, 0, r) {
        scanf(" %s", sol.farm[i]);
    }

    sol.simula();

    printf("%d %d\n", sol.ovelhas, sol.lobos);

    return 0;
}
