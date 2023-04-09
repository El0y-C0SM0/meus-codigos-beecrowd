#include <stdio.h>
 
int main() {
    int N, mult_2, mult_3, mult_4, mult_5;

    scanf("%d", &N);

    mult_2 = mult_3 = mult_4 = mult_5 = 0;

    for(int i = 0; i != N; i++){
        int L;
        scanf("%d", &L);
        if(L %  2 == 0) mult_2++;
        if(L % 3 == 0) mult_3++;
        if(L % 4 == 0) mult_4++;
        if(L % 5 == 0) mult_5++;
    }

    printf("%d Multiplo(s) de 2\n", mult_2);
    printf("%d Multiplo(s) de 3\n", mult_3);
    printf("%d Multiplo(s) de 4\n", mult_4);
    printf("%d Multiplo(s) de 5\n", mult_5);

    return 0;
}