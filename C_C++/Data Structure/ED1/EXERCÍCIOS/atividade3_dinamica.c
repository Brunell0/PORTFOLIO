#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 1000

struct No{
    char info;
    struct No *prox;
};

void push(struct No **topo, char *c){
    struct No *novo = malloc(sizeof(struct No));
    if (novo){
        novo->info = *c;
        novo->prox = *topo;
        *topo = novo;
        printf("Adicionado: %c\n", novo->info);
    }    
}

char pop(struct No **topo){
    struct No *aux;
    if (*topo != NULL){
        char elem = (*topo)->info;
        aux = *topo;
        *topo = aux->prox;
        free(aux);        
        printf("Removido: %c\n", elem);
        return elem;
    }else{
        printf("Underflow!\n");
    }
   
    return "0";
}

int main(){
    struct No *topo = NULL;
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
            push(&topo, &text[i]);
        }else{
            if (pop(&topo) != text[i]){
                pertence = false;
                break;
            }
        }
    }

    if (topo != NULL) pertence = false;

    if (pertence && achouC){
        printf("O texto pertence ao conjunto wCwr.");
    }else{
        printf("O texto NAO pertence ao conjunto wCwr.");
    }


    return 0;
}