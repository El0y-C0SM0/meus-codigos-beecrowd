#include <iostream>
#include <vector>

using namespace std;

vector<int> range_impar(int a, int b) {
    vector<int> vtr;
    int x = !(++b % 2);

    for(int i = b; i < a; i += 2) 
        vtr.push_back(i + x);
    
    return vtr;
}

int sum(vector<int> &vtr) {
    int sum = 0;

    for(int x: vtr)
        sum += x;

    return sum;
}

int main() {
    int a, b;
    cin >> a >> b;

    vector<int> nums = (a > b) ? range_impar(a, b) : range_impar(b, a);

    cout << sum(nums) << endl;

    return 0;
}