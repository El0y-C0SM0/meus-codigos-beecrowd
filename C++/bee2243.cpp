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

int main() {
    int maior=0, n, v[50002];
	scanf("%d", &n);
	v[0] = 0;
	v[n+1] = 0;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &v[i]);
		if (v[i] > v[i-1])
		{
			v[i] = v[i-1] + 1;
		}
	}
	for(int i = n; i >= 1; i--)
	{
		if (v[i] > v[i+1])
		{
			v[i] = v[i+1] + 1;
		}
	}
	for(int i = 0; i <= n; i++)
	{
		if (v[i] > maior) maior = v[i];
	}
	printf("%d\n", maior);
	return 0;
}
