#include <stdio.h>
 
int main() {
    int x, y, aux, soma;
    
    scanf("%d %d", &x, &y);

    if(x < y){
        aux = y;
        y = x;
        x = aux;
    }

    x--;

    if (x % 2 == 0) x--;

    for(soma = 0; x > y; x -= 2)
        soma += x;  

    printf("%d\n", soma);
    
    return 0;
}