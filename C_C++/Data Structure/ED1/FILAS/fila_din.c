#include <stdio.h>
#include <stdlib.h>
// FILA (DINÂMICA)

struct No{
    int info;
    struct No *prox;
};

void enqueue(struct No** inicio, struct No **fim, int x){ //adicionar
    struct No *aux = malloc(sizeof(struct No));
    if (aux){
        aux->info = x;
        aux->prox = NULL;
       if (*inicio == NULL) { //fila vazia
            *inicio = aux;
        } else { 
            (*fim)->prox = aux; 
        }
        *fim = aux; //atualiza quem é o novo fim
    }

}

void dequeue(struct No **inicio, struct No **fim, int *elem){ //remover
   if (*inicio == NULL){
    printf("Underflow!\n");
   }else{
    struct No *aux = *inicio;
    *elem = aux->info;
    *inicio = (*inicio)->prox;
    if (*inicio == NULL){ //esvaziou a fila
        *fim = NULL; //impede fim de apontar para lixo de memória
    }
    free(aux);
   }
}

void listagem(struct No *inicio){
    struct No *aux = inicio;
    while(aux != NULL){
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}

int contagem(struct No *inicio){
    int cont = 0;
    struct No *aux = inicio;
    while(aux != NULL){
        cont++;
        aux = aux->prox;
    }
    return cont;
}

int main(){
    struct No *inicio = NULL, *fim = NULL;
    int elem;
    enqueue(&inicio, &fim, 100);
    enqueue(&inicio, &fim, 200);
    enqueue(&inicio, &fim, 300);
    enqueue(&inicio, &fim, 400);

    listagem(inicio);

    dequeue(&inicio, &fim, &elem);
    printf("Item removido: %d\n", elem);
    dequeue(&inicio, &fim, &elem);
    printf("Item removido: %d\n", elem);

    listagem(inicio);
    printf("Contagem: %d\n", contagem(inicio));

    return 0;
}