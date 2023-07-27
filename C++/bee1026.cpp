#include <iostream>
 
using namespace std;

#define endl '\n';

typedef unsigned int uint;

int main() {
    uint a, b;

    while(cin >> a >> b) 
        cout << (a ^ b) << endl;
 
    return 0;
}