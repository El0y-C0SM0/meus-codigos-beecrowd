#include <bits/stdc++.h>

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define dbg(a) (cout << '\n' << #a << " = " << a << '\n')
#define loop(i,a,m) for(int i = a; i < m; ++i)
#define pb push_back
#define f first
#define s second
#define A 97

using namespace std;

typedef uint32_t uint;
typedef long long ll;
typedef long double ld;
typedef vector<int> vtr;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2001;

int tab[MAX][MAX];
int inic_seq[MAX][26];
string s1, s2;
int len1, len2;

void fill_tab(int i, int j) {
    if(tab[i][j]) return;

    if(!j) {
        tab[i][0] = 1;
        return;
    }

    if(!inic_seq[j][s1[i] - A]) {
        tab[i][j] = 1;
        return;
    }

    if(!i) {
        tab[0][j] = INF;
        return;
    }

    fill_tab(i - 1, j); 
    fill_tab(i - 1, inic_seq[j][s1[i] - A] - 1);

    tab[i][j] = min(tab[i - 1][j], tab[i - 1][inic_seq[j][s1[i] - A] - 1] + 1);
}

int solve(string &s1, string &s2) {
    loop(i, 0, 26)
        inic_seq[0][i] = 0;

    loop(i, 1, len2 + 1) {
        loop(j, 0, 26) {
            inic_seq[i][j] = inic_seq[i-1][j];
            if(s2[i-1] == (A + j)) {
                inic_seq[i][j] = i;
            }
        }
    }

    fill_tab(len1 - 1, len2);

    return tab[len1 - 1][len2];
}

int main() {_
    cin >> len1 >> len2;
    cin >> s1 >> s2;

    cout << solve(s1, s2) << endl;

    return 0;
}
