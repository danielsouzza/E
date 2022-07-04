#include<stdio.h>
#include<stdlib.h>

//Implemente Fila(Queue) usando alocação dinâmica(ponteiros)

typedef struct NO
{
    int dado;
    struct NO *prox;
}NO;

typedef struct FILA
{
    NO *ini;
    NO *fim;
}FILA;

void inicializaFila(FILA *f) //Inicializa a fila
{
    f->ini=NULL;
    f->fim=NULL;
}

void checkFilaVazia(FILA *f)
{
    NO *ptr = f -> ini;
    if(ptr == NULL)
    {
        printf("Fila vazia\n");
    }
    else{
        printf("Fila Tangente\n"); //Está preenchida
    }
}

void inserirFila(int dado, FILA *f) //Começa o enfileiramento
{
    NO *ptr = (NO*) malloc(sizeof(NO));
    if (ptr == NULL)
    {
        printf("Erro de alocação!\n");
    }else{
        ptr -> dado = dado;  //Inserir_Elemento
        ptr -> prox = NULL;
        if(f -> ini == NULL)
        {
            f -> ini = ptr;
        }else{
            f->fim->prox=ptr;
        }
        f -> fim = ptr; //fim atualizado, aponta p um novo elemento
    } 
}

void consultaFila(FILA *f) //Lê~Imprime topo da fila
{
    NO *ptr = f -> ini;
    if(ptr != NULL)
    {
        printf("Topo da fila: %d\n", ptr->dado);
    }
    else{
        printf("Fila vazia\n");
    }
    //return 1;
}

void imprimeFila(FILA *f) //Imprime do topo para a base da fila
{
    NO *ptr = f -> ini;
    if(ptr != NULL)
    {
        printf("Elementos na fila:\n");
        while(ptr != NULL)
        {
            printf("%3d", ptr->dado);
            ptr = ptr->prox;
        }
    }
    else{
        printf("Fila vazia\n");
    }
    //return 1;
}

void removeTopo(FILA *f) //Desenfileirar, Excluir_elemento (topo da fila)
{
    NO *ptr = f -> ini;
    int dado;
    if(ptr != NULL)
    {
        f->ini=ptr->prox;
        dado = ptr->dado;
        free(ptr);
        printf("Dado removido: %d\n", dado);
    }else{
        printf("Fila vazia\n");
    }

}

int main()
{
    FILA *q = (FILA*) malloc(sizeof(FILA));
    if(q==NULL)
    {
        printf("Erro na memória");
        exit(1);
    }else{
        inicializaFila(q);

        checkFilaVazia(q);

        inserirFila(1, q); //q aponta para a Struct FILA, q -> queue
        inserirFila(2, q);
        inserirFila(3, q);
        inserirFila(4, q);

        removeTopo(q);

        consultaFila(q);

        imprimeFila(q);
    }    
}







/*
free(q); //libera memória alocada
*/
