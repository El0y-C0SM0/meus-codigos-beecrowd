#include <bits/stdc++.h>

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define pb push_back
#define dbg(a) (cout << #a << " = " << a << '\n')
#define loop(a,m) for(int i = a; i < m; ++i)
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
    uint v, p, t;

    cin >> v >> p;

    t = v * p;
    
    loop(1, 10) {
        double perc = i / 10.0;
       
        cout << static_cast<int>(ceil(t * perc));
        
        if(i < 9) cout << ' ';
    }

    cout << endl;  
    
    return 0;
}
