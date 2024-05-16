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

string scs(string &s1, string &s2) {
    int m = s1.size(), n = s2.size();
    vector t(m + 1, vector<int>(n + 1, 0));

    for(int i{0}; i <= m; i++) {
        for(int j{0}; j <= n; j++) {
            if(!i) t[0][j] = j;
            else if(!j) t[i][0] = i;
            else if(s1[i - 1] == s2[j - 1]) t[i][j] = 1 + t[i - 1][j - 1];
            else t[i][j] = 1 + min(t[i - 1][j], t[i][j - 1]);
        }
    }

    string s = "";
    int len = t[m][n], i = m, j = n;

    while(len--) {
        if(i && j && s1[i - 1] == s2[j - 1]) {
            s += s1[i - 1];
            i--; j--;
        } else if(j && t[i][j] - 1 == t[i][j - 1]) {
            s += s2[j - 1];
            j--;
        } else if(i) {
            s += s1[i - 1];
            i--;
        }
    }

    reverse(s.begin(), s.end());

    return s;
}

int main() {_
    int teste{1};

    while(1) {
        string s1, s2;
        getline(cin, s1);

        if(s1[0] == '#') break;
        
        getline(cin, s2);

        cout << "Teste " << teste++ << endl;
        cout << scs(s1, s2) << endl << endl;
    }
    

    return 0;
}
