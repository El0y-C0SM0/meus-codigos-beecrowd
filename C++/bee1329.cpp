#include <iostream>

#define endl '\n'

using namespace std;

int main() {
	int n, m, j, aux;

	while(1) {
		m = 0; j = 0;

		cin >> n;
		if(!n) break;

		while(n) {
			n--;
			
			cin >> aux;

			if(aux) j++; else m++;
		}

		cout << "Mary won " << m << " times and Jonh won " << j << " times" << endl;
	}

	return 0;
}
