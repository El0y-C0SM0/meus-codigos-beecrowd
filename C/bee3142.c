#include <stdio.h>

int main() {
    while (1) {
        char vtr[11];
        vtr[0] = 0;
        vtr[1] = 0;
        vtr[2] = 0;

        char aux = 0;
        int cont = 0;
        for(int i = 0; aux != '\n'; i++) {
            if(scanf("%c", &aux) == EOF)
                return 0;
            else if(aux != '\n') {
                vtr[i] = aux - 64;
                cont++;
            }
        }

        int soma;

        if(cont == 1)
           soma = vtr[0];
        else if(cont == 2)
            soma = vtr[0] * 26 + vtr[1];
        else if(cont == 3)
            soma = vtr[0] * 676 + vtr[1] * 26 + vtr[2];
        else
            soma = 100000;

        if(soma <= 16384)
            printf("%d\n", soma);
        else
            printf("Essa coluna nao existe Tobias!\n");
    }

    return 0;
}