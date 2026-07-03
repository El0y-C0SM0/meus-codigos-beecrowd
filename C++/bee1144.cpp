#include <bits/stdc++.h>

/* Fast IO */
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

/* Functions */
#define dbg(a)          {cout << #a << " = " << a << '\n'}
#define loop(i,a,m)     for(int i = a; i < m; ++i)
#define loopt(t,i,a,m)  for(t i = a; i < m; ++i) 
#define fore(v)         for(auto &i:v)
#define fixed(n)        fixed << setprecision(n)
#define all(v)          (v).begin(),(v).end()
#define pb              push_back
#define fi               first
#define se               second

using namespace std;

/* Types */
typedef uint32_t uint;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef set<int> si;
typedef unordered_set<int> usi;

/* Prints */
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {_
    uint n; cin >> n;

    ull x, y;
    loopt(uint, i, 1, n+1) {
        x = i * i;
        y = i * i * i;

        cout << i << ' ' << x << ' ' << y << endl;
        cout << i << ' ' << x + 1 << ' ' << y + 1 << endl;
    }

    return 0;
}
