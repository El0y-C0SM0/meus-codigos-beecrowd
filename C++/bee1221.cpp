#include <bits/stdc++.h>

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define dbg(a) (cout << '\n' << #a << " = " << a << '\n')
#define loop(a,m) for(int i = a; i < m; ++i)
#define pb push_back
#define f first
#define s second

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef long double ld;
typedef vector<int> vtr;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int is_prime(uint n) {
    uint cont{0};

    for(uint i{2}; i <= sqrt(n); i++) {
        if(n % i == 0) {
            cont++;
            break;
        }
    }

    return cont == 0;
}

int main() {_
    int n; cin >> n;

    while(n--) {
        uint x; cin >> x;

        if(is_prime(x)) cout << "Prime" << endl;
        else cout << "Not Prime" << endl;
    }

    return 0;
}
