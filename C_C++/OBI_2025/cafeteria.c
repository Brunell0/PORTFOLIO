//NOTA 75/100
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int A, B, C, D, consegue = 0;
    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%d", &C);
    scanf("%d", &D);
    
	if(D == 0) D = 1;
 
    for (int i=0; i < C/D; i++){
        int j = C - (D * i);
        if(j >= A && j <= B){
            consegue = 1;
            break;
        }
    }

if(consegue){
    printf("S");
}else{
    printf("N");
}


    return 0;
}