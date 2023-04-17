#include <iostream>
#include <queue>
#include <string>

#define endl '\n'

using namespace std;

bool avalia_expressao(queue<char> &expressao) {
    int parenteses {0};

    while (!expressao.empty()) {
        char aux {expressao.front()};
        expressao.pop();

        if(aux == '(') 
            ++parenteses;
        else if(aux == ')' && parenteses > 0) 
            --parenteses;
        else {
            parenteses = 1;
            break;
        }
    }

    return !parenteses;
}

int main() {
    string input;

    while(cin >> input) {
        queue<char> equacao;

        for(char aux : input) {
            if(aux == '(' || aux == ')')
                equacao.push(aux);
        }
        
        if(avalia_expressao(equacao))
            cout << "correct" << endl;
        else
            cout << "incorrect" << endl;
    }
}