#include <bits/stdc++.h>

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
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

void histogram(vtr &hist, vtr &comp_alt) {
    stack<int> st;

    int i{0}, st_top, width, size = hist.size();
    while (i < size) {
        if(st.empty() || hist[st.top()] <= hist[i])
            st.push(i++);
        else {
            st_top = hist[st.top()]; st.pop();
            width = i;

            if(!st.empty()) width = i - st.top() - 1;

            if(comp_alt[st_top] < width)
                comp_alt[st_top] = width;
        }
    }
    

    while(!st.empty()) {
        st_top = hist[st.top()]; st.pop();
        width = i;

        if(!st.empty()) width = i - st.top() - 1;

        if(comp_alt[st_top] < width)
            comp_alt[st_top] = width;
    }
}

bool verify(par &p, vtr &comps, int max_size) {
    return (p.f <= max_size && p.s <= comps[p.f]) || (p.s <= max_size && p.f <= comps[p.s]);
}

int main() {_
    int n, m; cin >> n >> m;
    int c[1000][1000];

    char s[m];
    for(int i{0}; i < n; i++) {
        cin >> s;

        for(int j{0}; j < m; j++) {
            if(s[j] == '.') c[i][j] = 1;
            else c[i][j] = 0;
        }
    }

    int max_size = min(500, max(n, m));
    vtr comp_alt(max_size + 1, -1);
    vtr hist(m, 0);

    for(int i{0}; i < n; i++) {
        for(int j{0}; j < m; j++) 
            hist[j] = c[i][j] ? 1 + hist[j] : 0;
        
        histogram(hist, comp_alt);
    }

    int k; cin >> k;
    tuple<int, int, int> t{0, 0, 0}; 
    while (k--) {
        par p; cin >> p.f >> p.s;
        int x = p.f * p.s;

        if(x <= get<0>(t) && (x != get<0>(t) || p.s <= get<2>(t))) continue;
        else if(verify(p, comp_alt, max_size)) t = {x, p.f, p.s};
    }
    
    cout << get<1>(t) << ' ' << get<2>(t) << endl;

    return 0;
}
