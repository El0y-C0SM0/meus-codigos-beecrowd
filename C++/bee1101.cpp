#include <iostream>
#include <vector>

using namespace std;

int sum(vector<int> vtr) {
    int sum = 0;

    for(int x: vtr)
        sum += x;

    return sum;
}

vector<int> range(int ini, int fim) {
    vector<int> vtr;

    for(int i = ini; i <= fim; i++) 
        vtr.push_back(i);

    return vtr;
}

int main() {
    do {
        int m, n;

        cin >> m >> n;

        if(m <= 0 || n <= 0)
            break;

        vector<int> nums = (m > n) ? range(n, m) : range(m, n);

        for(int aux: nums)
            cout << aux << " ";
        cout << "Sum=" << sum(nums) << endl;
    } while (1);

    return 0;
}