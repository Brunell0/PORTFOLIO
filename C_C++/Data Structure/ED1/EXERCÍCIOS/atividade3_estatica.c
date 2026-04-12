#include <stdio.h>
#include <stdbool.h>
#define MAX 1000

void push(char p[], int *topo, char *c){
    if (*topo >= MAX - 1) printf("Overflow!\n");
    else{
        (*topo)++;
        p[*topo] = *c;
        printf("Adicionado: %c\n", p[*topo]);
    }
}

char pop(char p[], int *topo){
    if (*topo <= -1) printf("Underflow!\n");
    else{
        char elem = p[*topo];
        (*topo)--;
        printf("Removido: %c\n", elem);
        return elem;
    }
    return "0";
}

int main(){
    char pilha[MAX];
    int topo = -1;
    char text[MAX];
    bool pertence = true; //assumo que pertence e testo o contrário (similar ao algoritmo de números primos)

    printf("Digite a sequencia de caracteres:\n");
    scanf("%s", &text);
    printf("\n");

    
    bool achouC = false;
    for(int i = 0; text[i] != '\0'; i++){
        if (text[i] == 'C'){
            achouC = true;
            printf("Achou C!\n");
            continue;
        }
        if (!achouC){
            push(pilha, &topo, &text[i]);
        }else{
            if (pop(pilha, &topo) != text[i]){
                pertence = false;
                break;
            }
        }
    }

    if (topo != -1) pertence = false;

    if (pertence && achouC){
        printf("O texto pertence ao conjunto wCwr.");
    }else{
        printf("O texto NAO pertence ao conjunto wCwr.");
    }


    return 0;
}