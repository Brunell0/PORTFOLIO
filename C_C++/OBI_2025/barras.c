//NOTA 100/100
#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, maior=0, M;
    int** barras;
    int* val;
    
    scanf("%d", &N);
    
	val = (int*) calloc(N, sizeof(int));
	
    for(int i=0; i<N; i++){
        scanf("%d", &val[i]);
        if (val[i] > maior) maior = val[i];
    }
	
    barras = (int**) calloc(maior, sizeof(int*));
    
    for(int i=0; i<maior; i++){
        barras[i] = (int*) calloc(N, sizeof(int));
    }
    
    for(int i=0; i < N; i++){
    	for (int k=0; k < val[i]; k++){
    		barras[maior-k-1][i] = 1;
		}
	}
	
	for(int i=0; i<maior; i++){
		for(int j=0; j<N; j++){
			printf("%d ", barras[i][j]);
		}
		printf("\n");
	}
    return 0;
}