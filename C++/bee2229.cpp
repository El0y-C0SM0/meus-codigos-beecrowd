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

int main() {_
    uint i{1};

    while(1) {
        int n;
        cin >> n;
        if(n < 0) break;

        cout << "Teste " << i << endl;
        cout << static_cast<int>(pow(4, n) + pow(2, n +1) + 1) << endl << endl;

        i++;
    }
    
    return 0;
}
