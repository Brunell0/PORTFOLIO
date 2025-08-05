//NOTA 100/100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(){
    int E, S, L, total;
    scanf("%d", &E);
    scanf("%d", &S);
    scanf("%d", &L);

    total = abs(E - S) + abs(S - L) + abs(L - E);

    printf("%d", total);
    return 0;
}