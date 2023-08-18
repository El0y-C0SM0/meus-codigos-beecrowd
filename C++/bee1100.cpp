#include <bits/stdc++.h>

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(NULL);
#define pb push_back
#define f first
#define s second

using namespace std;

typedef vector<int> vtr;
typedef pair<int,int> coord;

// todos as mudanças de posições possiveis para um cavalo
vector<coord> moves = {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}};

// verifica se a posição é válida
bool val(coord a, int vis[8][8]) {
    return a.f >= 0 && a.s >= 0 && a.f < 8 && a.s < 8 && !vis[a.f][a.s];
}

// faz uma bfs até chegar em fim e retorna a distancia
int simula(coord ini, coord fim) {
    int vis[8][8] = {0};
    queue<pair<coord, int>> q;
    q.push({ini, 0});

    while (!q.empty()) {
        auto pos = q.front(); q.pop();

        for(coord e : moves) {
            e.f += pos.f.f;
            e.s += pos.f.s;

            if(val(e, vis) && e != fim) {
                q.push({e, pos.s + 1});
                vis[e.f][e.s] = 1;
            }
            else if(e == fim) return pos.s + 1;
        }
    }

    return 0;
}

int main() {_
    string a, b;

    while(cin >> a >> b){
        coord ini, fim;

        ini.f = a[0] - 97; ini.s = a[1] - 49;
        fim.f = b[0] - 97; fim.s = b[1] - 49;

        cout << "To get from " << a << " to " << b << " takes " << simula(ini, fim) << " knight moves." << endl;
    }

    return 0;
}
