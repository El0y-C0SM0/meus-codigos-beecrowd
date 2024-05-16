#include <bits/stdc++.h>

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define dbg(a) (cout << '\n' << #a << " = " << a << '\n')
#define loop(a,m) for(int K = a; K < m; ++K)
#define pb push_back
#define f first
#define s second

using namespace std;

typedef uint32_t uint;
typedef long long ll;
typedef long double ld;
typedef vector<int> vtr;
typedef pair<int, int> par;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int ilha[100][100];

bool valid(par &p) {
    return p.f >= 0 && p.f < 100 && p.s >= 0 && p.s < 100;
}

int main() {_
    memset(ilha, 0, sizeof ilha);
    int n, k; cin >> n >> k;

    loop(0, k) {
        par p; int d;
        cin >> p.f >> p.s >> d;

        par o{p.f + d, p.s};
        while(o.f > p.f) {
            if(valid(o)) ilha[o.f][o.s]++;
            o.f--; o.s++;
        }

        o = {p.f, p.s + d};
        while(o.s > p.s) {
            if(valid(o)) ilha[o.f][o.s]++;
            o.f--; o.s--;
        }

        o = {p.f - d, p.s};
        while(o.f < p.f) {
            if(valid(o)) ilha[o.f][o.s]++;
            o.f++; o.s--;
        }

        o = {p.f, p.s - d};
        while(o.s < p.s) {
            if(valid(o)) ilha[o.f][o.s]++;
            o.f++; o.s++;
        }        
    }


    int x{-INF}, flg{0}; par p;
    for(int i{0}; i < n; i++) {
        for(int j{0}; j < n; j++) {
            if(ilha[i][j] > x) {
                x = ilha[i][j];
                p = {i, j};
                flg = 0;
            } else if(ilha[i][j] == x) flg = 1;
        }
    }

    if(!flg) cout << p.f << ' ' << p.s << endl;
    else cout << "-1 -1" << endl;

    return 0;
}
