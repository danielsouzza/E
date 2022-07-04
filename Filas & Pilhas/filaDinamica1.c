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
        printf("Elementos na fila: ");
        while(ptr != NULL)
        {
            printf("%d ", ptr->dado);
            ptr = ptr->prox;
        }
        printf("\n");
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

void menu()
{
    printf("[1] - Insert element\n");
    printf("[2] - Show all data\n");
    printf("[3] - initialize queue\n");
    printf("[4] - Show Top element\n");
    printf("[5] - Check empty queue\n");
    printf("[6] - delete top element\n");
    printf("[0] - Exit\n");
}


int main()
{
    FILA *q = (FILA*) malloc(sizeof(FILA));
    int choce, dado;
    if(q==NULL)
    {
        printf("Erro na memória");
        exit(1);
    }
    while (choce != 0)
    {
        system("clear");
        menu();
        scanf("%d",&choce);
        fflush(stdin);
        system("clear");
        switch (choce)
        {  
            case 1:
                printf("Enter a value: ");
                scanf("%d", &dado);
                inserirFila(dado, q); //q aponta para a Struct FILA, q -> queue
                getchar();
                break;
            case 2:
                imprimeFila(q);
                getchar();getchar();
                break;
            case 3:
                inicializaFila(q);
                printf("Queue initialized...\n");
                getchar();
                break;
            case 4:
                consultaFila(q);
                getchar();getchar();
                break;
            case 5:
                checkFilaVazia(q);
                getchar();getchar();
                break;
            case 6:
                removeTopo(q);
                getchar();getchar();
                break;
        }
    }
    free(q);
}







/*
free(q); //libera memória alocada
*/
