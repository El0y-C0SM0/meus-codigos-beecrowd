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

bool check(string::iterator it_cifra, string::iterator it_crib, uint n) {
    while(n--) {
        if(*it_cifra == *it_crib) return false;
        it_cifra++; it_crib++;
    }

    return true;
}

int main() {_
    string cifra, crib;
    cin >> cifra >> crib;
    uint cont{0};

    loop(i, 0, cifra.length() - crib.length() + 1) {
        cont += check(cifra.begin() + i, crib.begin(), crib.length()); 
    }

    cout << cont << endl;

    return 0;
}
