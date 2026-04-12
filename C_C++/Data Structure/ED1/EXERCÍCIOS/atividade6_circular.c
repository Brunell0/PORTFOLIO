#include <stdio.h>
#include <stdlib.h>
//LISTA CIRCULAR (DINÂMICA)

struct No {
    int info;
    struct No *prox;
};

void inserir(struct No **p, int x) {
    struct No *novo = malloc(sizeof(struct No));
    novo->info = x;
    if (*p == NULL) { //primeiro nó
        *p = novo;
        novo->prox = *p;
    } else {
        struct No *aux = *p;
        while (aux->prox != *p) aux = aux->prox;
        aux->prox = novo;
        novo->prox = *p;
    }
}

void remover(struct No **p, int x) {
    struct No *aux = *p, *ant = *p;
    if (aux->info == x) { // primeiro nó
        if (aux->prox == *p) *p = NULL;
        else {
            struct No *ult = *p;
            while (ult->prox != *p) ult = ult->prox;
            *p = aux->prox; ult->prox = *p;
        }
        free(aux); return;
    }
    // Meio ou fim
    aux = aux->prox;
    while (aux != *p && aux->info != x) { ant = aux; aux = aux->prox; }
    if (aux != *p) { ant->prox = aux->prox; free(aux); }
    else printf("Nao encontrado\n");
}

void listagem(struct No *p) {
    if (!p) return;
    struct No *aux = p;
    do {
        printf("%d ", aux->info);
        aux = aux->prox;
    } while (aux != p);
}

int contagem(struct No *p) {
    if (!p) return 0;
    struct No *aux = p;
    int cont = 0;
    do {
        cont++;
        aux = aux->prox;
    } while (aux != p);
    return cont;
}

int main(){
    struct No *p = NULL;
    int x;
    scanf("%d", &x);
    
    for (int i=0; i < 10; i++){
        inserir(&p, x+i);
    }
    
    remover(&p, x);
    
    listagem(p);
    
    printf("\nContagem: %d", contagem(p));
    return 0;
}