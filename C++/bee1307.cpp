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
    int n; cin >> n;
    int p{1};

    while(n--) {
        string s1, s2;
        cin >> s1 >> s2;

        ll d1 = stol(s1, nullptr, 2); 
        ll d2 = stol(s2, nullptr, 2); 

        cout << "Pair #" << p++;
        if(gcd(d1, d2) > 1) cout << ": All you need is love!" << endl;
        else cout << ": Love is not all you need!" << endl;
    }
    
    return 0;
}

