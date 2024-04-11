#include <bits/stdc++.h>

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define dbg(a) (cout << '\n' << #a << " = " << a << '\n')
#define loop(a,m) for(int i = a; i < m; ++i)
#define pb push_back
#define f first
#define s second

using namespace std;

typedef uint32_t uint;
typedef long long ll;
typedef long double ld;
typedef vector<int> vtr;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n, cont = 1, arr[105];

int main() { _
    
    cin >> n;

    loop(0, n) {
        cin >> arr[i];
    }

    loop(1, n - 1) {
        int x = arr[i + 1] - arr[i];
        int y = arr[i] - arr[i - 1];
        if(x != y || y == 0 || x == 0) {
            i++; cont++;
        }
    }
    
    cout << cont << endl;
 
    return 0;
}
