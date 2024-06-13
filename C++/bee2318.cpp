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

int quad[9];

int lineSum(int l) {
    if(l < 3) l = 0;
    else if(l < 6) l = 3;
    else l = 6;

    return quad[l] + quad[l+1] + quad[l+2];
}

int collumSum(int c) {
    if(c > 2 && c < 6) c -= 3;
    else if(c > 5) c -= 6;

    return quad[c] + quad[c + 3] + quad[c + 6];
}

int primaryDiagonalSum() {
    return quad[0] + quad[4] + quad[8];
}

int secondaryDiagonalSum() {
    return quad[2] + quad[4] + quad[6];
}

int main() {_
    int x{0};

    loop(i, 0, 9)
        cin >> quad[i];

    loop(i, 0, 3) {
        if(quad[i] && quad[i+3] && quad[i+6])
            x = collumSum(i);
    }

    if(!x && quad[4]) 
        x = quad[4] * 3;
    else if(!x) {
        quad[4] = max(primaryDiagonalSum(), secondaryDiagonalSum()) / 2;
        x = quad[4] * 3;
    }

    quad[4] = x / 3;

    if(!quad[0]) 
        quad[0] = x - max(max(lineSum(0), collumSum(0)), primaryDiagonalSum());

    if(!quad[8]) 
        quad[8] = x - max(max(lineSum(8), collumSum(8)), primaryDiagonalSum());

    if(!quad[2]) 
        quad[2] = x - max(max(lineSum(2), collumSum(2)), secondaryDiagonalSum());

    if(!quad[6]) 
        quad[6] = x - max(max(lineSum(6), collumSum(6)), secondaryDiagonalSum());

    if(!quad[1]) 
        quad[1] = x - max(lineSum(1), collumSum(1));
        
    if(!quad[3]) 
        quad[3] = x - max(lineSum(3), collumSum(3));
        
    if(!quad[5]) 
        quad[5] = x - max(lineSum(5), collumSum(5));
        
    if(!quad[7]) 
        quad[7] = x - max(lineSum(7), collumSum(7));
        

    loop(i, 0, 9) {
        cout << quad[i] << ((i + 1) % 3 ? ' ' : endl);
    }

    return 0;
}
