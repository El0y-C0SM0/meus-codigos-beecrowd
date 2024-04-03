#include <iostream>
 
using namespace std;
 
int main() {
    int temp_a, temp_b, temp_c;
    int ftc_1, ftc_2;

    cin >> temp_a >> temp_b >> temp_c;

    ftc_1 = temp_b - temp_a;
    ftc_2 = temp_c - temp_b;

    if(ftc_1 < ftc_2 || (ftc_1 == ftc_2 && ftc_1 > 0 && ftc_2 > 0))
        cout << ":)" << endl;
    else
        cout << ":(" << endl;

    return 0;
}