#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int nome;
    int *batimentos;
    int intervalo;
    int dif;
    int mb;
} Ator;

void intervalo(int *vtr, int tam, int *dif, int *cresc, int *mb) {
    int ini = 0, fim = 0, maior_cresc = 0, aux = 0;

    if(tam != 1 && vtr[1] >= vtr[0])
        aux = 1;


    for(int i = 1; i < tam; i++) {
        if(vtr[i] >= vtr[i - 1]) {
            aux++;

            if(aux >= fim - ini){
                fim = i;
                ini = i - (aux - 1);
            }

        } else if(vtr[i] <= vtr[i - 1]) {
            if (aux > maior_cresc)
                maior_cresc = aux;
            
            aux = 1;
        }
        if(vtr[i] == vtr[i - 1])
            aux = 1;
    }
    if(aux > maior_cresc)
        maior_cresc = aux;

    if(tam != 1) {
        *cresc = maior_cresc;
        *dif = vtr[fim] - vtr[ini];
        *mb = vtr[fim];
    } else {
        *cresc = 0;
        *dif = 0;
        *mb = vtr[0];
    }
}

Ator *cria_ator(int nome, int quant) {
    Ator *ator = (Ator*) malloc(sizeof(Ator));
    ator->nome = nome + 1;

    ator->batimentos = (int*) malloc(quant * sizeof(int));

    for(int i = 0; i < quant; i++)
        scanf("%d", &ator->batimentos[i]);

    intervalo(ator->batimentos, quant, &ator->dif, &ator->intervalo, &ator->mb);

    return ator;
}

Ator *compara_batimentos(Ator **vtr, int tam) {
    Ator *ator, *aux;

    ator = vtr[0];

//    for(int i = 1; i < tam; i++)
//        printf("--%d--\n", vtr[i]->intervalo);

    for(int i = 1; i < tam; i++) {
        aux = vtr[i];

        if(aux->intervalo > ator->intervalo) 
            ator = vtr[i];
        else if(aux->intervalo < ator->intervalo) 
            continue;
        else if(aux->intervalo == ator->intervalo && aux->dif > ator->dif) 
            ator = vtr[i];
        else if(aux->intervalo == ator->intervalo && aux->dif == ator->dif && aux->mb > ator->mb) {
//            printf("--%d-%d--\n", ator->mb, aux->mb);
            ator = vtr[i];
        }
    }

    return ator;
}

int main() {
    int instancia = 1;
    int na, nb;

    while(1) {
        scanf("%d", &na);

        if(na == 0) 
            break;

        scanf("%d", &nb);

        Ator **lista = (Ator**) malloc(na * sizeof(Ator*));

        for(int i = 0; i < na; i++) 
            lista[i] = cria_ator(i, nb);

        Ator *ator = compara_batimentos(lista, na);

        printf("Instancia #%d\n", instancia);
        printf("%d\n\n", ator->nome);

        for(int i = 0; i < na; i++) {
            free(lista[i]->batimentos);
            free(lista[i]);
        }
        free(lista);

        instancia++;
    }

    return 0;
}


