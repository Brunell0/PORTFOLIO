#include <stdio.h>
#define MAX 100

void enqueue(int f[], int *fim, int x){
    if (*fim >= MAX - 1) printf("Overflow!\n");
    else{
        (*fim)++;
        f[*fim] = x;
    }
}

void separar_filas(int f[]){
    int fila_par[MAX], fila_impar[MAX];
    int inicio_par = -1, fim_par = -1;
    int inicio_impar = -1, fim_impar = -1;

    for(int j = 0; j < MAX; j++){
        if (f[j] % 2 == 0) enqueue(fila_par, &fim_par, f[j]);
        else enqueue(fila_impar, &fim_impar, f[j]);
        
    }
    
    printf("Fila par:\n");
    listagem(fila_par, inicio_par, fim_par);

    printf("Fila impar:\n");
    listagem(fila_impar, inicio_impar, fim_impar);
}


void listagem(int f[], int inicio, int fim){
    for(int i = inicio + 1; i <= fim; i++) printf("%d ", f[i]);
    printf("\n");
}

int main(){
    int fila[MAX];
    int inicio = -1, fim = -1;

    // fila NÃO vazia
    for (int i = 0; i < MAX; i++) enqueue(fila, &fim, i);
    printf("Fila pai:\n");
    listagem(fila, inicio, fim);

    separar_filas(fila);

    return 0;
}