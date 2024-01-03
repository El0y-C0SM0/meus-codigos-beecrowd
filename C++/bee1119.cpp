#include <bits/stdc++.h>

#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define f first
#define s second

using namespace std;

struct fdsp {
    int valor;
    fdsp *a;
    fdsp *p;
};

typedef pair<fdsp*, fdsp*> par_fdsp;

par_fdsp flg = {nullptr, nullptr};

void make_fdsp(int n) {
    fdsp *dsp = new fdsp;
    *dsp = {1, nullptr, nullptr};

    fdsp *cur = dsp;

    for(int i{2}; i <= n; i++) {
        cur->p = new fdsp;
        cur->p->a = cur;
        cur = cur->p;
        cur->valor = i;
        cur->p = nullptr;
    }

    cur->p = dsp;
    dsp->a = cur;

    flg.f = dsp;
    flg.s = dsp->a;
}

void select(int n) {
    if(n > 0) {
        fdsp *nd = flg.f; 

        while(n) {
            nd = nd->p;
            n--;
        }

        flg.f = nd;
    } else {
        fdsp *nd = flg.s; 

        while(n) {
            nd = nd->a;
            n++;
        }

        flg.s = nd;
    }
}

void clean(int &n) {
    if(flg.f->valor != flg.s->valor) {
        fdsp* el1 = flg.f;
        fdsp* el2 = flg.s;

        el1->a->p = el1->p; el1->p->a = el1->a;
        el2->a->p = el2->p; el2->p->a = el2->a;

        flg.f = (flg.f->p == flg.s) ? flg.s->p : flg.f->p;
        flg.s = (flg.s->a == flg.s) ? flg.f->a : flg.s->a;

        n -= 2;

        delete el1; delete el2;
    } else {
        fdsp* el = flg.f;

        el->a->p = el->p; el->p->a = el->a;

        flg.f = flg.f->p;
        flg.s = flg.s->a;

        n--;

        delete el;
    }
}

void print() {
    if(flg.f->valor == flg.s->valor) cout << setw(3) << flg.f->valor;
    else cout << setw(3) << flg.f->valor << ' ' << setw(2) << flg.s->valor;
}

int main() {
    int n, k, m;

    while(1) {
        cin >> n >> k >> m; 

        if(!n && !k && !m) return 0;

        k--; m--;
        m *= -1;

        make_fdsp(n);

        while(n) {
            select(k);
            select(m);

            print();

            clean(n);

            if(n > 0) cout << ',';
        }
        
        cout << endl;
    }

    return 0;
}