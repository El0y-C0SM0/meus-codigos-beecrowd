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


int main() { _
    int n, xo, yo, xf, yf, xmin, ymin, xmax, ymax, area = 0;
    bool visitado[100][100];
    memset(visitado, false, sizeof(visitado));

    cin >> n;

    while(n--) {
        cin >> xo >> xf >> yo >> yf;
        
        xmax = max(xo, xf); ymax = max(yo, yf);
        xmin = min(xo, xf); ymin = min(yo, yf);

        for(int i = ymin; i < ymax; i++) {
            for(int j = xmin; j < xmax; j++) {
                if(not visitado[i][j]) {
                    visitado[i][j] = true;
                    area++;
                }
            }
        }
    }

    cout << area << endl;
 
    return 0;
}
