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
    int n, m; cin >> n >> m;
    vtr nums; nums.pb(0);
    loop(i, 0, 30) {
        int x; cin >> x;
        nums.pb(x + nums[i]);
    }

    int dif{m - n}, i{30};
    while (n < m) {
        // int media = (nums[i] - nums[i-30]) / 30;
        int media = ceil((nums[i] - nums[i-30]) / 30.0);
        n += media;
        nums.pb(media + nums[i]);
        i++;
    }
    
    cout << i - 30 << endl;

    return 0;
}
