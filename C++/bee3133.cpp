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

class ComparaNavios {
public:
    bool operator()(const par &a, const par &b) const {
        return (a.f + (-a.s)) < (b.f + (-b.s));
    }
};

inline int max(par p) {
    return max(p.f, p.s);
}

inline int min(par p) {
    return min(p.f, p.s);
}

int main() {_
    int n; cin >> n;
    priority_queue<par, vector<par>, ComparaNavios> pq;

    while(n--) {
        int a, b; cin >> a >> b;
        pq.push({a, b});
    }

    int sum = pq.top().f; pq.pop();
    sum += pq.top().f; pq.pop();
    sum += pq.top().f; pq.pop();
    while(!pq.empty()) {
        sum += pq.top().s; pq.pop();
    }

    cout << sum << endl;

    return 0;
}
