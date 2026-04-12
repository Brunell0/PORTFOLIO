#include <stdio.h>
#define MAX 100
// FILA CIRCULAR

void enqueue(int f[], int inicio, int *fim, int x){ //adicionar
    if ((*fim + 1) % MAX == inicio){
        printf("Overflow!\n");
    }else{
        *fim = (*fim + 1) % MAX;
        f[*fim] = x;
    }
}

void dequeue(int f[], int *inicio, int fim, int *x){ //remover
    if (*inicio == fim){
        printf("Underflow!\n");
    }else{
        (*inicio) = (*inicio + 1) % MAX;
        *x = f[*inicio]; // retorna o valor de quem foi removido
    }
}

void listagem(int f[], int inicio, int fim){
    for(int i = (inicio+1)%MAX; i != (fim+1)%MAX; i = (i+1)%MAX){
        printf("[%d] = %d\n", i, f[i]); //indice meramente ilustrativo para visualizacao da circularidade
    }
}

int contagem(int inicio, int fim){
    int cont = 0;
    for(int i = (inicio+1)%MAX; i != (fim+1)%MAX; i = (i+1)%MAX){
        cont++;
    }
    return cont;
}

int main(){
    int fila[MAX];
    int inicio = 0, fim = 0;
    int removido=-1;

    for (int i=0; i<20; i++){
        enqueue(fila, inicio, &fim, 100);
        enqueue(fila, inicio, &fim, 200);
        enqueue(fila, inicio, &fim, 300);
        enqueue(fila, inicio, &fim, 400);
        enqueue(fila, inicio, &fim, 500);
    }
    
    enqueue(fila, inicio, &fim, 600);
    
    dequeue(fila, &inicio, fim, &removido);
    dequeue(fila, &inicio, fim, &removido);
    dequeue(fila, &inicio, fim, &removido);
    printf("Removido: %d\n", removido);
    dequeue(fila, &inicio, fim, &removido);
    
    enqueue(fila, inicio, &fim, 700);

    listagem(fila, inicio, fim);
    printf("Contagem %d", contagem(inicio, fim));
    return 0;
}