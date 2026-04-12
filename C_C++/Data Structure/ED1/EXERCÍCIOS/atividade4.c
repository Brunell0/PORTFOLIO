#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

int array[MAX];

char emptyStack1(int p[], int topo){
    return topo <= -1 ? 'V' : 'F';
}

char emptyStack2(int p[], int topo){
    return topo >= MAX ? 'V' : 'F';
}

char fullArray(int topo1, int topo2){
    return topo1 >= topo2 - 1 ? 'V' : 'F';
}

void push_all(int p[], int *topo1, int *topo2, int x){
    if (fullArray(*topo1, *topo2) == 'V') printf("Overflow!\n");
    else{
        // empilha na pilha 1
        (*topo1)++;
        p[*topo1] = x;
        printf("Adicionado (pilha 1): %d\n", p[*topo1]);
        
        // empilha na pilha 2
        (*topo2)--;
        p[*topo2] = x;
        printf("Adicionado (pilha 2): %d\n", p[*topo2]);
    }
}


void pop_all(int p[], int *topo1, int *topo2, int *elem1, int *elem2){
    if (emptyStack1(p, *topo1) == 'V' || emptyStack2(p, *topo2) == 'V') printf("Underflow!\n");
    else{
        // removido da pilha 1
        *elem1 = p[*topo1];
        p[*topo1] = -1; // apenas para visualização na listagem
        printf("Removido (pilha 1): %d\n", *elem1);
        (*topo1)--;

        // removido da pilha 2
        *elem2 = p[*topo2];
        p[*topo2] = -1; // apenas para visualização na listagem
        printf("Removido (pilha 2): %d\n", *elem2);
        (*topo2)++;
    }
}

void inicializar(){
    for(int i=0; i < MAX; i++) array[i] = -1;
}

void listagem(int p[]){
    for(int i=0; i < MAX; i++) printf("%d\n", p[i]);
}

int main(){
    int topo1 = -1, topo2 = MAX, removido1, removido2;
    inicializar();
    // pilhas vazias
    printf("Pilha 1 vazia: %c\n", emptyStack1(array, topo1));
    printf("Pilha 2 vazia: %c\n", emptyStack2(array, topo2));

    push_all(array, &topo1, &topo2, 10);
    push_all(array, &topo1, &topo2, 20);
    push_all(array, &topo1, &topo2, 30);

    pop_all(array, &topo1, &topo2, &removido1, &removido2);

    printf("Full Array: %c\n", fullArray(topo1, topo2));
    
    listagem(array);

    return 0;
}