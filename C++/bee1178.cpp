#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    double x;

    cin >> x;
    
    for(int i = 0; i < 100; i++, x /= 2) 
        printf("N[%d] = %.4lf\n", i, x);
    
    return 0;
}