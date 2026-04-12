#include <stdio.h>
#define MAX 100
// FILA (ESTÁTICA)

void enqueue(int f[], int *fim, int x){ //adicionar
    if (*fim >= MAX - 1){
        printf("Overflow!\n");
    }else{
        (*fim)++;
        f[*fim] = x;
    }
}

void dequeue(int f[], int *inicio, int fim, int *x){ //remover
    if (*inicio == fim){
        printf("Underflow!\n");
    }else{
        (*inicio)++;
        *x = f[*inicio]; // retorna o valor de quem foi removido
    }
}

void listagem(int f[], int inicio, int fim){
    if (inicio == fim){
        printf("Nada para ser listado!\n");
    }else{
        for(int i = inicio+1; i <= fim; i++){
            printf("%d ",f[i]);
        }
        printf("\n");
    }
}

int contagem(int inicio, int fim){
    int cont = 0;
    for(int i = inicio+1; i <= fim; i++){
        cont++;
    }
    return cont;
}

int main(){
    int fila[MAX];
    int inicio = -1, fim = -1;
    int removido;

    enqueue(fila, &fim, 100);
    enqueue(fila, &fim, 200);
    enqueue(fila, &fim, 300);
    
    dequeue(fila, &inicio, fim, &removido);
    printf("Removido: %d\n", removido);
    
    dequeue(fila, &inicio, fim, &removido);
    printf("Removido: %d\n", removido);
    
    listagem(fila, inicio, fim);
    printf("Contagem: %d\n", contagem(inicio, fim));

    return 0;
}