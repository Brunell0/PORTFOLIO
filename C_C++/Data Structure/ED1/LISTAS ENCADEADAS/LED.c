#include <stdio.h>
#include <stdlib.h>

// LISTA ENCADEADA DINÂMICA: inserção, remoção, contagem, listagem

struct No{
    int info;
    struct No *prox;
};

void adicionar_fim(struct No **p, int val){
    struct No *novo = malloc(sizeof(struct No));
    struct No *aux;

    if (novo){
        novo->info = val;
        novo->prox = NULL;
        if (*p == NULL){ //primeiro da lista
            *p = novo;
        }else{
            aux = *p;

            while (aux->prox != NULL){
                aux = aux->prox;
            }
            
            aux->prox = novo;


        }
    }
}

void adicionar_inicio(struct No **p, int val){
    struct No *novo = malloc(sizeof(struct No));

    if (novo){ //malloc funcionou
        novo->info = val;
        novo->prox = *p;
        *p = novo;
    }
}

void remover(struct No **p, int val){
    struct No *aux = *p;
    struct No *ant = NULL;
    while(aux != NULL && aux->info != val){
        ant = aux;
        aux = aux->prox;
    }
    if (aux != NULL) { // Achou o nó
        if (ant == NULL) *p = aux->prox; // Era o primeiro
        else ant->prox = aux->prox;      // Estava no meio/fim
        free(aux);
    }else{
        printf("O numero nao existe na lista.\n");
    }
}

void listagem(struct No *p){
    struct No *aux = p;
    while (aux != NULL){
        printf("%d -> ", aux->info);
        aux = aux->prox;
    }
}

int contagem(struct No *p){
    struct No *aux = p;
    int cont = 0;
    while (aux != NULL){
        cont++;
        aux = aux->prox;
    }
    return cont;
}

void remove_ultimo(struct No **p){
    if (*p == NULL){
        printf("Lista vazia!\n");
    }else{
        struct No *aux = *p;
        struct No *ant = NULL;

        while (aux->prox != NULL){
            ant = aux;
            aux = aux->prox;
        }
        if (ant == NULL){
            *p = NULL;
        }else{
            ant->prox = NULL;
        }
        free(aux);
    }
}

void liberar(struct No **p) {
    struct No *aux;
    while (*p != NULL) {
        aux = *p;
        *p = (*p)->prox;
        printf("\n%p\n", aux);
        free(aux);
    }
}

int main(){
    struct No *p = NULL;
    int x, y;
    
    for (int i=1; i<=3;i++){
        printf("Digite o numero %d a ser adicionado: ", i);
        scanf("%d", &x);
        adicionar_fim(&p, x);
    }
    adicionar_inicio(&p, 100);

    printf("\nQual numero quer remover? ");
    scanf("%d", &y);
    remover(&p, y);

    remove_ultimo(&p);
    
    listagem(p);

    printf("\nCONTAGEM: %d", contagem(p));
    
    liberar(&p);
    return 0;
}