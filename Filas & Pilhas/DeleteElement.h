#include <stdio.h>
#include <stdlib.h>

typedef struct Step
{
    int dado;
    struct Step * prox;
}Step;

typedef struct Pilha
{
    Step * top;
    int size;
}Pilha;

int deleteMy(int dado, Pilha *pilha)
{
    Step * remover = pilha->top; // Step = No de uma pilha 
    Step * ptr = NULL;
    while (remover != NULL)
    {
        if(remover->dado == dado){
            if(ptr == NULL){
                pilha->top = NULL;
                free(remover);
            }else{
                ptr->prox = remover->prox;
                free(remover);
            }
            return dado;
        }
        ptr = remover;
        remover = ptr->prox;
    }
    printf("pilha vazia ou elemento nao encontrado\n");
    return 0;
}