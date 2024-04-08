#include <bits/stdc++.h>

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define dbg(a) (cout << '\n' << #a << " = " << a << '\n')
#define loop(a,m) for(uint32_t i = a; i < m; ++i)
#define pb push_back
#define f first
#define s second

using namespace std;

typedef uint32_t uint;
typedef long long ll;
typedef long double ld;
typedef vector<uint> vtr;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main() {_
    uint a, v, i{1};

    while (1) {
        cin >> a >> v;
        if(!a && !v) break;

        vtr aer = vtr(a, 0);

        loop(0, v) {
            uint x, y;
            cin >> x >> y; x--; y--;

            aer[x]++;
            aer[y]++;
        }


        auto print = [&](){
            uint cong{0};
            vtr out;

            for(auto &i : aer) cong = i > cong ? i : cong;

            loop(0, a) if(aer[i] == cong) cout << i + 1 << ' ';
            cout << endl;
        };

        cout << "Teste " << i++ << endl;
        print();
        cout << endl;
    }
    


    return 0;
}
