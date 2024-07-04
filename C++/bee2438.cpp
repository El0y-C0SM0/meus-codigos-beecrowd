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
	int n; cin >> n;
	ll sum{0}, cont{0};
	vector<ll> nums(10);
	nums[0] = 1;

	loop(i, 0, n) {
		int x; cin >> x;
		sum += x;
		sum %= 8;
		
		cont += nums[sum];

		nums[sum]++;
	}

	cout << cont << endl;

	return 0;
}
