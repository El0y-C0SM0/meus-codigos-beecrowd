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
	ll safra{0};
	vector<ll> frutas(101, 0);
	vtr climas(n, 0);

	loop(i, 1, k+1) {
		ll x; cin >> x;
		frutas[x]++;
	}

	for(int &i : climas) {
		char c; cin >> c;
		i = c == 'C' ? 1 : -1;
	}

	loop(i, 1, 101) {
		ll cur{i};

		for(int j{0}; j < n && cur > 0; j++) {
			cur += climas[j];
			safra += cur * frutas[i];
		}
	}

	cout << safra << endl;

	return 0;
}
