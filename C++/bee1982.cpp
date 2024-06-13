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

int orientation(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
    int x = (p2.second - p1.second) * (p3.first - p2.first)
        - (p2.first - p1.first) * (p3.second - p2.second);

    return x;
}

int distPow(pair<int, int> &p1, pair<int, int> &p2) {
    return (p1.first - p2.first) * (p1.first - p2.first) + 
                (p1.second - p2.second) * (p1.second - p2.second);
}

void grahanScan(vector<pair<int, int>> &fig, vector<pair<int, int>> &hull) {
    pair<int, int> p0 = *min_element(fig.begin(), fig.end(), [&](auto &a, auto &b){
        return make_pair(a.second, a.first) < make_pair(b.second, b.first);
    });

    sort(fig.begin(), fig.end(), [&p0](auto &a, auto &b){
        int o = orientation(p0, a, b);

        if(o == 0) 
            return distPow(p0, a) < distPow(p0, b);
        
        return o < 0;
    });
    
    hull.push_back(fig[0]); hull.push_back(fig[1]);
    
    uint k = hull.size();
    for(uint i{2}; fig[0] != fig[i] && i < fig.size(); i++) {
        while (k >= 2 && orientation(hull[k - 2], hull[k - 1], fig[i]) > 0) {
            hull.pop_back();
            k--;
        }
        hull.push_back(fig[i]);
        k++;
    }
}

int main() {_
    cout << fixed << setprecision(2);

    while(1) {
        int n; cin >> n;
        if(!n) break;
    
        vector<par> pontos(n);

        loop(i, 0, n) 
            cin >> pontos[i].f >> pontos[i].s;

        vector<par> borda;
        grahanScan(pontos, borda);

        double dist = 0;
        loop(i, 1, static_cast<int>(borda.size()) + 1) {
            par &a = borda[i % borda.size()];
            par &b = borda[i - 1];

            dist += sqrt(distPow(a, b));
        }

        cout << "Tera que comprar uma fita de tamanho " << dist << ".\n";
    }

    return 0;
}
