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
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {_
    int l, c, m, n;
    int a[1000][1000], b[1000][1000];
    
    cin >> l >> c >> m >> n;
    
    for(int i{0}; i < l; i++)
        for(int j{0}; j < c; j++)
            cin >> a[i][j];
            
    for(int i{0}; i < l; i++) {
        b[i][0] = 0;
       
        for(int j{0}; j < n; j++)
            b[i][0] += a[i][j];
            
        for(int j{1}; j < c-n+1; j++)
            b[i][j] = b[i][j-1] + a[i][j+n-1] - a[i][j-1];
    }
    
    for(int j{0}; j < c-n+1; j++) {
        a[0][j] = 0;
        
        for(int i{0}; i < m; i++)
            a[0][j] += b[i][j];
        
        for(int i{1}; i < l-m+1; i++) 
            a[i][j] = a[i-1][j] + b[i+m-1][j] - b[i-1][j];
    }
    
    int x{0};
    for(int i{0}; i < l-m+1; i++) {
        for(int j{0}; j < c-n+1; j++) x = max(x, a[i][j]);
    }
                
    cout << x << endl;

    return 0;
}
