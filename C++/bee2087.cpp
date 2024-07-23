#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define dbg(a) (cout << #a << " = " << a << '\n')
#define loop(i,a,m) for(int i = a; i < m; ++i)
#define pb push_back

using namespace std;

typedef uint32_t uint;
typedef long long ll;
typedef long double ld;
typedef vector<int> vtr;
typedef pair<int,int> par;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Node {
    bool end;
    char val;
    unordered_map<char, Node*> children;

    Node() {
        val = 0;
        end = false;
    }

    Node(char a) {
        val = a;
        end = false;
    }

    Node *getOrAddChildren(const char a) {
        if(children.count(a) != 0)
            return children[a];

        return children[a] =  new Node(a);
    }

    int countChildren() {
        return children.size();
    }

    ~Node() {
        for(auto &[key, child] : children)
            delete child;
    }
};

class Trie {
private:
    Node *root;

public:
    Trie() {
        root = new Node();
    }

    bool add_string(string &s) {
        Node *cur = root;

        for(char &c : s) {
            cur = cur->getOrAddChildren(c);
            if(cur->end)
                return true;
        }

        if(cur->countChildren() > 0)
            return true;

        cur->end = true;
        return false;
    }
};

int main() {_
    uint n;

    while(1) {
        Trie trie;

        cin >> n;
        if(!n) break;

        bool good{true};
        while(n--) {
            string s; cin >> s;

            if(good)
                good = !trie.add_string(s);
        }

        cout << "Conjunto " << (good ? "Bom" : "Ruim") << endl;
    }

    return 0;
}