#include <stdio.h>
#include <stdlib.h>

struct No{
    int info;
    struct No *prox;
};


void enqueue(struct No **inicio, struct No **fim, int x){
    struct No *novo = malloc(sizeof(struct No));

    if (novo){
        novo->info = x;
        novo->prox = NULL;

        if (*inicio == NULL) *inicio = novo; //fila estava vazia
        else (*fim)->prox = novo;
        *fim = novo;
    }
}

void separar_filas(struct No **inicio){
    struct No *inicio_par = NULL, *fim_par = NULL;
    struct No *inicio_impar = NULL, *fim_impar = NULL;
    struct No *aux = *inicio;
    
    while(aux != NULL){
        if (aux->info % 2 == 0) enqueue(&inicio_par, &fim_par, aux->info);
        else enqueue(&inicio_impar, &fim_impar, aux->info);
        aux = aux->prox;
    }
    
    printf("Fila par:\n");
    listagem(inicio_par);

    printf("Fila impar:\n");
    listagem(inicio_impar);
}


void listagem(struct No *inicio){
    struct No *aux = inicio;
    while(aux != NULL){
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}

int main(){
    struct No *inicio = NULL, *fim = NULL;

    // fila NÃO vazia
    for (int i = 0; i < 50; i++) enqueue(&inicio, &fim, i);
    printf("Fila pai:\n");
    listagem(inicio);

    separar_filas(&inicio);

    return 0;
}