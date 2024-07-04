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
	vtr folhas(3);
	int intervalo;
	cin >> folhas[0] >> folhas[1] >> folhas[2];

	sort(folhas.begin(), folhas.end());

	intervalo = folhas[0];
	intervalo += (folhas[1] > folhas[0] + 200) ? folhas[1] - (folhas[0] + 200) : 0;
	intervalo += (folhas[2] > folhas[1] + 200) ? folhas[2] - (folhas[1] + 200) : 0;
	intervalo += 600 - (folhas[2] + 200);

	cout << intervalo * 100 << endl;

	return 0;
}
