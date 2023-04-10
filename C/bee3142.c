#include <stdio.h>

int main() {
    while (1) {
        int coluna = 0;
        char aux = 0;
        
        while(1) {
            if(scanf("%c", &aux) == EOF)
                return 0;
            
            if(aux != '\n')
                coluna = (coluna * 26) + (aux - 64);
            else
                break;
        }

        if(coluna <= 16384)
            printf("%d\n", coluna);
        else
            printf("Essa coluna nao existe Tobias!\n");
    }

    return 0;
}
