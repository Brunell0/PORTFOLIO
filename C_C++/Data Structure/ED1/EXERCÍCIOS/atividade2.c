#include <stdio.h>
#include <stdlib.h>

struct No{
    int info;
    struct No *prox;
};

void inserir(struct No **L, int val){
    struct No *novo = malloc(sizeof(struct No));
    struct No *aux;
    if (novo){
        novo->info = val;
        novo->prox = NULL;
        if (*L == NULL) *L = novo;
        else{
            aux = *L;
            while(aux->prox != NULL) aux = aux->prox;
            aux->prox = novo;
        }
    }
}

/* Assuma que os valores de Vi e Vf estão contidos em L,
 e que Vi não é o primeiro nó e Vf não é o último nó da lista.*/
void remover_intervalo(struct No **L, int Vi, int Vf){
    struct No *aux = *L;
    struct No *ant = NULL;

    // chegamos no Vi (primeiro a ser removido)
    while(aux != NULL && aux->info != Vi){
        ant = aux;
        aux = aux->prox;
    }
    // a lista é ordenada, logo haverá a remoção enquanto o valor for menor ou igual que Vf
    while(aux->info <= Vf){
        printf("Removido: %d\n", aux->info);
       
        ant->prox = aux->prox;
        aux = aux->prox;
        // free(aux);
    }
}

// mera visualização
void listagem(struct No *L){
    struct No *aux = L;
    
    while(aux != NULL){
        printf("%d -> ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}

int main(){
    struct No *L = NULL;
    int Vi = 50, Vf = 89; // Vi < Vf
    
    for (int i=0; i < 150; i++) inserir(&L, i); // lista ordenada
    
    // mera visualização
    listagem(L);

    remover_intervalo(&L, Vi, Vf);

    // mera visualização
    listagem(L);

    return 0;
}