#include <stdio.h>
#define MAX 10

struct No{
    int info, prox;
};

void inicializar(struct No f[], int *dispo){
    for (int i=0; i < MAX-1; i++){
        f[i].prox = i+1;
    }
    f[MAX-1].prox = -1;
    *dispo = 0;
}

void adicionar(struct No f[], int *L, int *dispo, int x){
    if (*dispo == -1) printf("Overflow");
    else{
        int n = *dispo;
        *dispo = f[*dispo].prox;
        f[n].info = x;
        f[n].prox = *L;
        *L = n;
    }
}

/* Assuma que os valores de Vi e Vf estão contidos em L,
 e que Vi não é o primeiro nó e Vf não é o último nó da lista.*/
void remover_intervalo(struct No f[], int *L, int *dispo, int Vi, int Vf){
    int aux = *L, ant = -1;

    // Chegamos no Vi
    while(aux != -1 && f[aux].info != Vf){
        ant = aux;
        aux = f[aux].prox;
    }
    //Como o vetor é ordenado e estamos em Vi, vamos até Vf
    while(f[aux].info >= Vi){
        printf("Removido: %d\n", f[aux].info);

        int proximo_no = f[aux].prox; //salva o nó

        f[ant].prox = proximo_no;
        f[aux].prox = *dispo;
        *dispo = aux;
        aux = proximo_no;
    }

}

void listagem(struct No f[], int L){
    for(int i=L; i!=-1; i = f[i].prox){
        printf("%d ", f[i].info);
    }
    printf("\n");
}

int main(){
    struct No lista[MAX];
    int L = -1, dispo;
    int Vi = 2, Vf = 6; // Vi < Vf

    inicializar(lista, &dispo);

    for(int i = 0; i < MAX; i++){
        adicionar(lista, &L, &dispo, i);
    }

    listagem(lista, L);
    
    remover_intervalo(lista, &L, &dispo, Vi, Vf);

    listagem(lista, L);
    return 0;
}