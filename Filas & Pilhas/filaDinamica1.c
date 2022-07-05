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
    printf("Fila inicializada!\n\n");
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
    printf("[1] - Check_Fila_vazia\n");
    printf("[2] - Inserir_Elemento\n");
    printf("[3] - Excluir_Elemento_Topo\n");
    printf("[4] - Lê_Topo_Fila\n");
    printf("[5] - Imprimir_Fila\n");
    printf("[0] - Exit\n\n");
}

int main()
{
    FILA *q = (FILA*) malloc(sizeof(FILA));
    int opc, dado;
    if(q==NULL)
    {
        printf("Erro na memória");
        exit(1);
    }
    inicializa(q);
    while (opc != 0)
    {
        menu();
        scanf("%d",&choce);
        fflush(stdin);
        system("clear");
        switch(opc)
        {  
            case 1:
                checkFilaVazia(q);
                getchar();getchar();
                break;
            case 2:
                printf("Insira um elemento: ");
                scanf("%d", &dado);
                inserirFila(dado, q); //'q' aponta para a Struct FILA
                getchar();
                break;
            case 3:
                removeTopo(q);
                getchar();getchar();
                break;
            case 4:
                consultaFila(q);
                getchar();getchar();
                break;
            case 5:
                imprimeFila(q);
                getchar();getchar();
                break;
        }
        system("clear");
    }
    free(q); //libera a memória alocada
}
