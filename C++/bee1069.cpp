#include <iostream>
#include <queue>
#include <string>

#define endl '\n'
#define uint unsigned int

using namespace std;

int main() {
    uint num_casos;

    cin >> num_casos;
    cin.ignore(2, '\n');

    for(uint i = 0; i < num_casos; ++i) {
        string input;
        queue<char> fragmentos;
        int diamantes {0};

        cin.clear();
        getline(cin, input);

        for(char chr : input) {
            if(chr == '<') 
                fragmentos.push(chr);
            else if(chr == '>' && !fragmentos.empty()) {
                fragmentos.pop();
                diamantes++;
            }
        }

        cout << diamantes << endl;
    }

    return 0;
}
