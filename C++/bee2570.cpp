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
    char t[1000][1000]; memset(t, 'A', sizeof t);
    char part[] = {'R','H','C','P'};
    int n, m, k; cin >> n >> m >> k;

    loop(0, k) {
        char o; int id;
        cin >> o >> id; id--;
        int x = i % 4;

        if(o == 'L') {
            for(int j{0}; j < m; j++) t[id][j] = part[x];
        } else {
            for(int j{0}; j < n; j++) t[j][id] = part[x];
        }
    }

    unordered_map<char,int> vals = {{'R', 0},{'H', 0},{'C', 0},{'P', 0}};
    for(int i{0}; i < n; i++) {
        for(int j{0}; j < m; j++) if(t[i][j] != 'A') vals[t[i][j]]++;
    }

    cout << 'R' << vals['R'] << ' ';
    cout << 'H' << vals['H'] << ' ';
    cout << 'C' << vals['C'] << ' ';
    cout << 'P' << vals['P'] << endl;

    return 0;
}
