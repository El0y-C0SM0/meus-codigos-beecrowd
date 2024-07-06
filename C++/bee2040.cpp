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

int main() {_
    int n; 
    
    while(1) {
        cin >> n; if(!n) break;

        unordered_map<string, int> times;

        loop(i, 0, n) {
            string nome; cin >> nome;
            int pontos; cin >> pontos;
            times[nome] = pontos;
        }

        loop(i, 0, n / 2) {
            string time1, time2;
            int gols1, gols2; 
            cin >> time1 >> gols1 >> gols2 >> time2;
            gols2 *= -1;

            if(gols1 > gols2) times[time1] += 5;
            else if(gols1 < gols2) times[time2] += 5;
            else {
                times[time1] += 1;
                times[time2] += 1;
            }

            times[time1] += gols1 * 3;
            times[time2] += gols2 * 3;
        }

        pair<string, int> campeao{"null", -INF};
        for(auto &i : times) if(i.s > campeao.s) campeao = i;

        if(campeao.f == "Sport") cout << "O Sport foi o campeao com " << campeao.s << " pontos :D" << endl;
        else cout << "O Sport nao foi o campeao. O time campeao foi o " << campeao.f << " com " << campeao.s << " pontos :(" << endl;
        cout << endl;
    }

    return 0;
}
