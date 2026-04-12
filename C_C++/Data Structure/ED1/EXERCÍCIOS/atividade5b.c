#include <stdio.h>
#include <stdbool.h>
#define MAX 41

void enqueue(int f[], int *fim, int inicio, int x){
    if ((*fim + 1) % MAX == inicio) printf("Overflow!\n");
    else{
        *fim = (*fim + 1) % MAX;
        f[*fim] = x;
    }
}

void listagem(int f[], int inicio, int fim){
    for(int i=(inicio+1) % MAX; i!=(fim+1) % MAX; i=(i+1)%MAX){
        printf("%d ", f[i]);
    }
    printf("\n");
}

int contagem(int f[], int inicio, int fim){
    int cont=0;
    for(int i=(inicio+1) % MAX; i!=(fim+1) % MAX; i=(i+1)%MAX){
        cont++;
    }
    return cont;
}

void new_queue(int f1[], int f2[]){
    int fila3[MAX];
    int inicio = -1, fim = -1;
    int k = 0, j = k; // controla quais valores já foram inseridos da fila2
    bool inserido;

    for(int i=0; i < MAX/2; i++){
        inserido = false;
        for (j=k; j < MAX/2; j++){
            if (f1[i] > f2[j]){
                enqueue(fila3, &fim, inicio, f2[j]);
                i--;
                k++;
                inserido = true;
                break;
            }
        }
        if (!inserido){
            enqueue(fila3, &fim, inicio, f1[i]);
        }
        if (i + 1 ==  MAX / 2){ // se o próximo i for a condição de parada
            for (j=k; j < MAX/2; j++){
                enqueue(fila3, &fim, inicio, f2[j]);
            }
        }
    }

    printf("Fila 3:\n");
    listagem(fila3, inicio, fim);

    printf("Contagem: %d\n", contagem(fila3, inicio, fim));
}

int main(){
    int fila1[MAX], fila2[MAX];
    int inicio1 = -1, fim1 = -1;
    int inicio2 = -1, fim2 = -1;

    //geração de alguns valores ORDENADOS
    for (int i=0; i < MAX/2; i++){
        enqueue(fila1, &fim1, inicio1, (i-1)*2);
        enqueue(fila2, &fim2, inicio2, (i+2)*3);
    }

    printf("Fila 1 (contagem: %d):\n", contagem(fila1, inicio1, fim1));
    listagem(fila1, inicio1, fim1);

    printf("Fila 2 (contagem: %d):\n", contagem(fila2, inicio2, fim2));
    listagem(fila2, inicio2, fim2);

    new_queue(fila1, fila2);

    return 0;
}