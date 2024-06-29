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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct par {
    int f, s;

    par(int f, int s) : f(f), s(s) {}
    par(int x=0) : f(x), s(x) {
        if(!x) f = s = INF;
        else if(x == 1) f = s = 0;
    } 

    par operator*(par other) {
        if((this->f == INF && this->s == INF) || (other.f == INF && other.s == INF))
            return 0;

        if(!this->f && !this->s)
            return other;

        if(!other.f && !other.s)
            return *this;

        return {this->f + other.f, this->s + other.s};
    }

    inline int min() {
        return std::min(f, s);
    }
};

const par PAR_0(0);
const par PAR_1(1);

class Solution {
private:
    vector<vector<par>> m;
    int n;
    vtr pow2{1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288};
    vtr pow5{1, 5, 25, 125, 625, 3125, 15625, 78125, 390625};

    int aproximateLog2(int i) {
        if(i == 0) return INF;

        int expo = 19, x = pow2[expo];

        while(i % x != 0 && expo >= 0) {
            expo--;
            x = pow2[expo];
        }

        return expo;
    }

    int aproximateLog5(int i) {
        if(i == 0) return INF;

        int expo = 8, x = pow5[expo];

        while(i % x != 0 && expo >= 0) {
            expo--;
            x = pow5[expo];
        }

        return expo;
    }

public:
    Solution(int n) : n(n) {
        m = vector<vector<par>>(n, vector<par>(n));
    }

    inline void add(int x, int i, int j) {
        m[i][j] = par(aproximateLog2(x), aproximateLog5(x));
    }

    int solve() {
        vector<vector<par>> r(n+1, vector<par>(n+1, PAR_0));
        r[0][1] = r[1][0] = PAR_1;

        loop(i, 1, n+1) loop(j, 1, n+1) {
            r[i][j] = m[i-1][j-1] * par(min(r[i-1][j].f, r[i][j-1].f), min(r[i-1][j].s, r[i][j-1].s));
        }

        return r[n][n].min();
    }    
};

int main() {_
    int n; cin >> n;

    Solution solution(n);

    loop(i, 0, n) loop(j, 0, n) {
        int x; cin >> x;
        solution.add(x, i, j);
    }

    cout << solution.solve() << endl;

    return 0;
}
