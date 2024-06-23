#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define dbg(a) (cout << #a << " = " << a << '\n')
#define loop(i,a,m) for(int i = a; i < m; ++i)
#define pb push_back
#define f first
#define s second
#define VIS -1

using namespace std;

typedef uint32_t uint;
typedef long long ll;
typedef long double ld;
typedef vector<int> vtr;
typedef pair<int,int> par;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int moz[202][202];
vector<par> movs{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool isValid(par p, int cor) {
    return moz[p.f][p.s] != VIS && moz[p.f][p.s] == cor;
}

int floodFill(int i, int j, int &cont, int cor) {
    cont++;
    moz[i][j] = VIS;
    
    for(auto m : movs) {
        m.f += i; m.s += j;
        if(isValid(m, cor)) floodFill(m.f, m.s, cont, cor);
    }
    
    return cont;
}

int find(int h, int l) {
    int area{INF};

    loop(i, 1, h+1) loop(j, 1, l+1) if(moz[i][j] != VIS) {
        int cont{0}, cor{moz[i][j]};
        floodFill(i, j, cont, cor);
        area = min(area, cont);
    }

    return area;
}

int main() {_
    int h, l; cin >> h >> l;
    memset(moz, -1, sizeof moz);
    loop(i, 1, h+1) loop(j, 1, l+1) cin >> moz[i][j];

    cout << find(h, l) << endl;

    return 0;
}
