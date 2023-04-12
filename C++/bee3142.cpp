#include <cstdio>
// usei o metodo de entrada scanf() para pegar o '\n'

using namespace std;

int main() {
    int coluna = 0;
    char letra;

    while(scanf("%c", &letra) != EOF) {
        if(letra != '\n')
            coluna = (coluna * 26) + letra - 64;
        else if(coluna <= 16384 && coluna > 0) {
            printf("%d\n", coluna);
            coluna = 0;
        } 
        else {
            printf("Essa coluna nao existe Tobias!\n");
            coluna = 0;
        }
    }

    return 0;
}
