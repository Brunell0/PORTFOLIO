#include <stdio.h>

void transferir(int n, char de, char para, char temp, int* quant){
    if (n > 0){
        transferir(n - 1, de, temp, para, quant);
        printf("Mover o disco %d de %c para %c\n", n, de, para);
        (*quant)++;
        transferir(n - 1, temp, para, de, quant);
    }
}

int main(){
    int n, qtd = 0;

    printf("Quantos discos?\n");
    scanf("%d", &n);
    printf("\n");

    transferir(n, 'E', 'D', 'C', &qtd);
    printf("Quantidade de movimentos: %d", qtd);
}