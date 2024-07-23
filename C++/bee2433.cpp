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
    int n, k; cin >> n >> k;
    vtr nums(n);
    for(int &i : nums) cin >> i;
    sort(nums.begin(), nums.end());

    auto right{nums.begin()}, left{nums.begin() + (n - k - 1)};
    int distancia{INF};
    while(left != nums.end()) {
        distancia = min(distancia, *left - *right);
        right++; left++;
    }

    cout << distancia << endl;

    return 0;
}
