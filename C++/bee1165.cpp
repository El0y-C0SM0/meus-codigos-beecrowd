#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
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

uint menor_fator_primo(uint n) {
    for (uint i {2}; i * i <= n; i++) if (!(n % i))
        return i;
    return n;
}

bool is_prime(uint n) {
    return n > 1 && menor_fator_primo(n) == n;
}

int main() {_
    uint x, n;
    cin >> x;

    while (x--) {
        cin >> n;
        if (is_prime(n)) cout << n << " eh primo";
        else cout << n << " nao eh primo";
        cout << endl;
    }

    return 0;
}
