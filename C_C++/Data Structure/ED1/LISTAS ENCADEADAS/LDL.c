#include <stdio.h>
#include <stdlib.h>
    
struct No {
    int info;
    struct No *ant, *prox;
};
//LISTA DUPLAMENTE ENCADEADA/LIGADA

void adicionar_fim(struct No **p, int val) {
    struct No *novo = malloc(sizeof(struct No));
    if (novo) {
        novo->info = val;
        novo->prox = NULL;
        if (*p == NULL) {
            novo->ant = NULL;
            *p = novo;
        } else {
            struct No *aux = *p;
            while (aux->prox != NULL) aux = aux->prox;
            aux->prox = novo;
            novo->ant = aux;
        }
    }
}

void adicionar_inicio(struct No **p, int val) {
    struct No *novo = malloc(sizeof(struct No));
    if (novo) {
        novo->info = val;
        novo->ant = NULL;
        novo->prox = *p;
        if (*p != NULL) (*p)->ant = novo;
        *p = novo;
    }
}

void remover(struct No **p, int val) {
    struct No *aux = *p;
    while (aux != NULL && aux->info != val) aux = aux->prox;

    if (aux != NULL) { 
        if (aux->ant == NULL) { //era o primeiro
            *p = aux->prox;
            if (*p != NULL) (*p)->ant = NULL;
        } else {
            aux->ant->prox = aux->prox;
            if (aux->prox != NULL) aux->prox->ant = aux->ant;
        }
        free(aux);
    } else {
        printf("Numero nao existe na lista.\n");
    }
}

void listagem(struct No *p) {
    while (p != NULL) {
        printf("%d <-> ", p->info);
        p = p->prox;
    }
    printf("NULL\n");
}

int contagem(struct No *p) {
    int cont = 0;
    while (p != NULL) {
        cont++;
        p = p->prox;
    }
    return cont;
}

void remove_ultimo(struct No **p) {
    if (*p == NULL) return;
    struct No *aux = *p;
    while (aux->prox != NULL) aux = aux->prox;

    if (aux->ant == NULL) *p = NULL;
    else aux->ant->prox = NULL;
    
    free(aux);
}

void liberar(struct No **p) {
    struct No *aux;
    while (*p != NULL) {
        aux = *p;
        *p = (*p)->prox;
        free(aux);
    }
}

int main() {
    struct No *p = NULL;
    adicionar_fim(&p, 10);
    adicionar_fim(&p, 20);
    adicionar_inicio(&p, 5);
    
    listagem(p); // 5 <-> 10 <-> 20
    remover(&p, 10);
    listagem(p); // 5 <-> 20
    
    printf("Contagem: %d\n", contagem(p));
    liberar(&p);
    return 0;
}