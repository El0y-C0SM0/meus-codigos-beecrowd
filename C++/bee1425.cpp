#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define dbg(a) (cout << #a << " = " << a << '\n')
#define loop(i,a,m) for(int i = a; i < m; ++i)
#define pb push_back
#define f first
#define s second
#define C 2

using namespace std;

typedef uint32_t uint;
typedef long long ll;
typedef long double ld;
typedef vector<int> vtr;
typedef pair<int,int> par;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool simula(int n, int m) {
    if(m > 34) return 1;

    queue<par> q; q.push({1, 3});

    while(!q.empty()) {
        par x{q.front()}; q.pop();

        if(x.f == m) return true;

        if(x.f + x.s <= n) q.push({x.f + x.s, x.s + C});
        if(x.f - x.s > 0) q.push({x.f - x.s, x.s + C});
    }

    return false;
}

int main() {_
    int n, m;
    while(1) {
        cin >> n >> m;
        if(!n) break;

        if(simula(n, m)) cout << "Let me try!" << endl;
        else cout << "Don't make fun of me!" << endl;
    }

    return 0;
}
