// ! Erro de 5%
#include <bits/stdc++.h>

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define dbg(a) (cout << '\n' << #a << " = " << a << '\n')
#define loop(a,m) for(int i = a; i < m; ++i)
#define pb push_back
#define ins insert
#define f first
#define s second

using namespace std;

typedef uint32_t uint;
typedef long long ll;
typedef long double ld;
typedef vector<int> vtr;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int repit(unordered_map<int, int> &crts) {
    pair<int, int> x{0, 0};

    int i{0};
    for(auto &crt : crts) {
        if(i == crts.size() - 1) x = crt; 
        i++;
    }

    return x.f;
}

int sequence(unordered_map<int, int> &crts) {
    vector<pair<int, int>> cpy(crts.begin(), crts.end());

    loop(1, static_cast<int>(cpy.size())) {
        if(cpy[i].f != cpy[i - 1].f + 1) return 0;
    }

    return 1;
}

void sort(unordered_map<int, int> &crts) {
    vector<pair<int, int>> cpy(crts.begin(), crts.end());

    sort(cpy.begin(), cpy.end(), [](auto& a, auto& b) {
        if(a.s > b.s || (a.s == b.s && a.f > b.f))
            return 1;
        return 0;
    });

    unordered_map<int, int> sorted_crts;
    for(auto &it : cpy) {
        sorted_crts.ins(it);
    }

    crts = sorted_crts;
}

int main() {_
    uint i{1}, n; cin >> n;

    while (i <= n) {
        uint cont{0};
        unordered_map<int, int> crts;
        set<int> st;
        
        loop(0, 5) {
            int x;
            cin >> x;

            if(st.count(x))
                crts[x]++;
            else {
                st.ins(x);
                crts.ins({x, 1});
            }
        }

        sort(crts);

        if(st.size() == 5 && sequence(crts)) cont = crts.begin()->f + 200; // 5 diferentes em sequencia
        else if(st.size() == 4) cont = repit(crts); // uma dupla
        else if(st.size() == 3) {
            if((++crts.begin())->s == 1) cont = repit(crts) + 140; // 1 trinca
            else // 2 dupla
                cont = 3 * (++(++crts.begin()))->f + 2 * (++crts.begin())->f + 20;
        } else if(st.size() == 2) {
            if(crts.begin()->s == 1) cont = repit(crts) + 180; // quadra
            else cont = repit(crts) + 160; // 1 trinca 1 dupla
        } else cont = 0; // todas diferentes
        
        cout << "Teste " << i << endl;
        cout << cont << endl << endl;

        i++;
    }

    return 0;
}