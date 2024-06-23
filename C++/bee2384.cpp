#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define dbg(a) (cout << #a << " = " << a << '\n')
#define loop(i,a,m) for(ll i = a; i < m; ++i)
#define pb push_back

using namespace std;

typedef uint32_t uint;
typedef long long ll;
typedef unsigned long long ull;

const ull MOD = 1e9+7;

string n, s; 
uint n_size, s_size;

inline bool is_valid(uint begin, uint end) {
    return end - begin < n_size || (end - begin == n_size && string_view(s.data()+begin, end - begin) <= n);
}

int main() {_
    cin >> n >> s; 
    n_size = n.size(); s_size = s.size();
    ull memo[s_size+2];
    memo[s_size+1] = memo[s_size] = 1;
 
    for(ll b{s_size - 1}; b >= 0; --b) {
        memo[b] = 0;
        if(s[b] == '0') continue;
        
        for(ll i{b + 1}; i <= s_size; i++) {
            if(is_valid(b, i)) 
                memo[b] += memo[i];
            else break;
        } 

        memo[b] %= MOD;
    }

    cout << memo[0] << endl;    

    return 0;
}