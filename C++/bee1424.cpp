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
    int n, m; 
    
    while(cin >> n >> m) {
        unordered_map<int, vtr> nums;

        loop(i, 1, n+1) {
            int x; cin >> x;
            nums[x].pb(i);
        }

        loop(i, 0, m) {
            int x, y; cin >> x >> y;

            if(x <= nums[y].size()) cout << nums[y][x - 1] << endl;
            else cout << 0 << endl;
        }
    }

    return 0;
}
