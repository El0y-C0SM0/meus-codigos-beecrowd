#include <iostream>

using namespace std;

int main() {
    int alcool = 0, gasolina = 0, diesel = 0;
    int escolha;

    do {
        cin >> escolha;

        switch (escolha) {
        case 1:
            alcool++;
            break;
        case 2:
            gasolina++;
            break;
        case 3:
            diesel++;
            break;
        case 4:
            cout << "MUITO OBRIGADO\n";
            cout << "Alcool: " << alcool << '\n';
            cout << "Gasolina: " << gasolina << '\n';
            cout << "Diesel: " << diesel << endl;
            return 0;
            break;
        }
    } while(1);

    return 0;
}