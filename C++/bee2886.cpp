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
const double distMax = 50 * sqrt(2);

struct Point {
    double x, y;

    Point() : x(0), y(0) {}
    Point(double _x, double _y) : x(_x), y(_y) {}
};

double distPoint(Point p, Point o) {
    return sqrt((p.x - o.x) * (p.x - o.x) + (p.y - o.y) * (p.y - o.y));
}

struct Circle {
    Point centro;
    double raio;
    
    Circle(Point _centro, double _raio) : centro(_centro), raio(_raio) {}
    Circle() : centro(), raio(0) {}

    int intersections(Circle c) {
        double dist = distPoint(centro, c.centro);

        if(dist > raio + c.raio || dist < abs(raio - c.raio))
            return 0;
        if(dist == raio + c.raio || dist == abs(raio - c.raio))
            return 1;

        return 2;
    }
};

uint solve(vector<Circle> orbitas, uint n) {
    uint cont{0};

    for(uint i{0}; i < n && cont <= 2 * n + 1; i++) {
        for(uint j{i+1}; j < n && cont <= 2 * n + 1; j++) {
            if(abs(orbitas[i].raio - orbitas[j].raio) > distMax)
                break;
            cont += orbitas[i].intersections(orbitas[j]);
        }
    }

    return cont;
}

int main() {_
    uint n; cin >> n;

    vector<Circle> orbitas(n);


    for(Circle &i : orbitas) {
        double x, y, r; cin >> x >> y >> r;
        i = Circle(Point(x, y), r);
    }

    sort(orbitas.begin(), orbitas.end(), [](Circle &a, Circle &b){
        return a.raio < b.raio;
    });

    uint res = solve(orbitas, n);
    if(res <= 2 * n) cout << res << endl;
    else cout << "greater" << endl;

    return 0;
}
