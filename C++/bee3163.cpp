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

int main() {
    vector<queue<string>> filas(4);

    int card_point, cont{0};
    while(1) {
        string input; cin >> input;
        if(input[0] == '0') break;

        if(input[0] == '-') card_point = input[1] - 49;
        else {
            filas[card_point].push(input);
            cont++;
        }
    }

    while(!filas[0].empty() || !filas[1].empty() || !filas[2].empty() || !filas[3].empty()) {
        if(!filas[0].empty()) {
            cout << filas[0].front();
            filas[0].pop();
            cont--;
            cout << (!cont ? endl : ' ');
        }


        if(!filas[2].empty()) {
            cout << filas[2].front();
            filas[2].pop();
            cont--;
            cout << (!cont ? endl : ' ');
        }
        
 
        if(!filas[1].empty()) {
            cout << filas[1].front();
            filas[1].pop();
            cont--;
            cout << (!cont ? endl : ' ');
        }
        

        if(!filas[3].empty()) {
            cout << filas[3].front();
            filas[3].pop();
            cont--;
            cout << (!cont ? endl : ' ');
        }
        
    }

    return 0;
}
