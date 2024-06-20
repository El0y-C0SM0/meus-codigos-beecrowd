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
typedef tuple<int,int,int> trio;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

class Solution {
private:
    int k, n;
    int pontos[101][101];

public:
    vector<trio> cars;
    
    Solution(int k, int n) : k(k), n(n), cars(vector<trio>(n + 1, {0, 0, 0})) {
        memset(pontos, -1, sizeof pontos);
    }

    void markCheckpoint(int x, int y, int i) {
        auto [a, b, c]{cars[x]};

        if(b + 1 == y) {
            a++; b = y % k;
            pontos[x][b] = i;
        }

        cars[x] = {a, b, x};
    }

    void getRank() {
        sort(cars.begin(), cars.end(), [&](auto x, auto y){
            auto [a, b, c]{x};
            auto [d, e, f]{y};

            if(a > d) return true;
            if(a < d) return false;
            if(pontos[c][b] > pontos[f][e]) return false;

            return true;
        });
    }
};

int main() {_
    int k, n, m; cin >> k >> n >> m;
    Solution solution(k, n);

    loop(i, 0, m) {
        int x, y; cin >> x >> y;
        solution.markCheckpoint(x, y, i);
    }

    solution.getRank();

    loop(i, 0, n) 
        cout << get<2>(solution.cars[i]) << (i == (n - 1) ? endl : ' ');

    return 0;
}
