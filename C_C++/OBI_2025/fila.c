//NOTA 60/100
#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, nao_enxerga = 0, j;
	int* a;
	
	scanf("%d", &N);
	a = (int*) malloc(N*sizeof(int));
	
	for(int i=0; i<N; i++){
		scanf("%d", &a[i]);
	} 
	
	for(int i=0; i < N-1; i++){
		for(int j=N-1; j >= 0; j--){
			if (a[j] >= a[i]){
				if (j <= i) break;
				nao_enxerga++;
				break;
			}
		}
	}
	
	printf("%d", nao_enxerga);
	return 0;
}