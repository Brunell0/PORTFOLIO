#include <stdio.h>
struct No
{ int info, prox; };

#define MAX 5
// LISTA ENCADEADA ESTÁTICA

void inicializar(struct No f[], int *dispo) {
    for (int i = 0; i < MAX - 1; i++) f[i].prox = i + 1;
    f[MAX - 1].prox = -1;
    *dispo = 0;
}

void adicionar(struct No f[], int *L, int *dispo, int x) {
    if (*dispo == -1) return;
    int n = *dispo;
    *dispo = f[*dispo].prox;
    f[n].info = x;
    f[n].prox = *L;
    *L = n;
}

void remover(struct No f[], int *L, int *dispo, int x) {
    int aux = *L, ant = -1;
    while (aux != -1 && f[aux].info != x) { ant = aux; aux = f[aux].prox; }
    if (aux != -1) {
        if (ant == -1) *L = f[aux].prox;
        else f[ant].prox = f[aux].prox;
        f[aux].prox = *dispo;
        *dispo = aux;
    } else printf("Nao encontrado\n");
}

void listagem(struct No f[], int L) {
    for (int i = L; i != -1; i = f[i].prox) printf("[%d] ", f[i].info);
    printf("\n");
}

int contagem(struct No f[], int L) {
    int c = 0;
    for (int i = L; i != -1; i = f[i].prox) c++;
    return c;
}

int main() {
    struct No lista[MAX];
    int L = -1, dispo;

    inicializar(lista, &dispo);
    adicionar(lista, &L, &dispo, 10);
    adicionar(lista, &L, &dispo, 20);
    
    listagem(lista, L);
    printf("Total: %d\n", contagem(lista, L));
    
    remover(lista, &L, &dispo, 10);
    listagem(lista, L);
    
    return 0;
}