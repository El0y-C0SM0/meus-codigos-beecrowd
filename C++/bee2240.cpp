#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define dbg(a) (cout << #a << " = " << a << '\n')
#define loop(a,m) for(int i = a; i < m; ++i)
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

struct fk_tree {
    int n;
    vtr e, c, d;

    fk_tree(int n) : n(n), e(vtr(n, 0)), c(vtr(n, 0)), d(vtr(n, 0)) {}

    void add(int i, int x, char p) {
        if(i < 0 || x < 0) return;

        switch(p) {
            case 'e':
                e[i] = x;
                break;
            case 'c':
                c[i] = x;
                break;
            case 'd':
                d[i] = x;
                break;
        }
    }
};

int max_sdc(fk_tree &t, int i, vtr &vis) {
    if(vis[i]) return vis[i];

    if(t.c[i] == 0) vis[i] = 1;
    else vis[i] = max_sdc(t, t.c[i], vis) + 1;

    return vis[i];
}

int main() {_
    int n; cin >> n;
    fk_tree te(n);
    vtr vis_e(n, 0);
    
    loop(0, n) {
        int j, l, k;
        cin >> j >> l >> k;
        te.add(j - 1, k - 1, 'c');
    }

    int e1{max_sdc(te, 0, vis_e)};
    int max_sdc_e{0};
    loop(0, n) {
        max_sdc_e = max(max_sdc_e, max_sdc(te, i, vis_e));
    }

    int m; cin >> m;
    fk_tree td(m);
    vtr vis_d(m, 0);

    loop(0, m) {
        int p, q, r;
        cin >> p >> q >> r;
        td.add(p - 1, q - 1, 'c');
    }

    int d1{max_sdc(td, 0, vis_d)};
    int max_sdc_d{0};
    loop(0, m) {
        max_sdc_d = max(max_sdc_d, max_sdc(td, i, vis_d));
    }
    
    cout << te.n + td.n - max(min(e1, max_sdc_d), min(d1, max_sdc_e)) << endl;

    return 0;
}
