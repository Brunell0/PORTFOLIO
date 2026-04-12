#include <stdio.h>
#include <stdlib.h>
// PILHA (DINÂMICA)

struct No{
    int info;
    struct No *prox;
};

void push(struct No **topo, int x){
    struct No *aux = malloc(sizeof(struct No));
    if (aux){
        aux->info = x;
        aux->prox = *topo;
        *topo = aux;
    }
}

void pop(struct No **topo, int *elem){
    struct No *aux;
    if (*topo){
        *elem = (*topo)->info;
        aux = *topo;
        *topo = aux->prox;
        free(aux);
    }else{
        printf("Underflow!\n");
    }
}

void listagem(struct No *topo){
    struct No *aux = topo;
    while(aux != NULL){
        printf("%d \n", aux->info);
        aux = aux->prox;
    }
}

int contagem(struct No *topo){
    struct No *aux = topo;
    int cont = 0;

    while(aux != NULL){
        cont++;
        aux = aux->prox;
    }
    
    return cont;
}

int main(){
    struct No *topo = NULL;
    int removido;

    push(&topo, 100);
    push(&topo, 300);
    push(&topo, 200);
    push(&topo, 400);

    pop(&topo, &removido);
    printf("Removido: %d\n", removido);

    listagem(topo);

    pop(&topo, &removido);
    printf("Removido: %d\n", removido);

    printf("\nTotal: %d", contagem(topo));

    return 0;
}
