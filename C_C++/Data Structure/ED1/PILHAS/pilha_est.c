#include <stdio.h>
#define MAX 100
// PILHA (ESTÁTICA)

void push(int p[], int *topo, int x){
    if (*topo >= MAX - 1){
        printf("Pilha cheia!\n");
    }else{
        (*topo)++;
        p[*topo] = x;
    }
}

void pop(int p[], int *topo, int *y){
    if (*topo <= -1){
        printf("Pilha vazia!\n");
    }else{
        *y = p[*topo];
        printf("%d foi removido da pilha!\n", *y);
        (*topo)--;
    }
}

void imprimir(int p[], int topo){
    // a impressão ocorre de cima para baixo
    for (int i = topo; i >= 0; i--){
        printf("%d\n", p[i]);
    }
}

int contagem(int topo){
    return topo + 1;
}

int main(){
    int pilha[MAX];
    int topo = -1;
    int removido;

    push(pilha, &topo, 100);
    push(pilha, &topo, 300);
    push(pilha, &topo, 200);
    imprimir(pilha, topo);
    pop(pilha, &topo, &removido);
    printf("Itens na pilha: %d", contagem(topo));


    return 0;
}
