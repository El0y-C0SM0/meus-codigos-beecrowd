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

int main() {_
    int n; cin >> n;
    stack<int> st;
    map<int, int> nums;

    while(n--) {
        string instruction; cin >> instruction;

        if(instruction == "PUSH") {
            int x; cin >> x;
            st.push(x);
            nums[x]++;
        } else if(st.empty()) {
            cout << "EMPTY" << endl;
        } else if(instruction == "POP") {
            int x = st.top(); st.pop();

            if(nums[x] > 1) nums[x]--;
            else nums.erase(x);
        } else {
            cout << nums.begin()->f << endl;
        }
    }

    return 0;
}
