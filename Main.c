#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quickSort.h"
#DEFINE T 10 // Tamanho do vetor teste

// Função para printar
void print(int vetor[], int size)
{
    printf("[");
    for(int i = 0; i <= size; i++){
        printf("%3d", vetor[i]);
    }
    printf("  ]");
    printf("\n");
}

// Gerar um vetor aleatorio
void generateVector(int * vetor)
{
    char insp; // inspeciona se existe um número repetido
    srand(time(NULL)); // Gera uma semente conforme o tempo
    for (int i = 0; i < T; i++)
    {
        vetor[i] = rand() % 20;
        insp = 'n';
        for(int j = 0; j<i && insp == 'n'; j++)
        {
            if (vetor[i] == vetor[j])
            {
                insp = 's';
            }
        }
        if(insp == 's')
        {
            i--; //impede o incremento e sorteia novamente
        }
    }
}

// Inverte o vetor
void invertVector(int vetor[])
{
    int mid = t / 2;
    for(int i = 0, j = t-1; i < mid; i++, j--)
    {
        int aux = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = aux;
    }
}

void main()
{
    double tempo; // Armazena o tempo da ordenação
    time_t t_start, t_end;// tempo inicial e tempo final

    int vetor[T];
    
    generateVector(vetor);
    print(vetor);

    // Testando Quick Sort
    
    t_start = time(NULL); 
    mergeSort(vetor, 0, end); // Chama o algoritmo que está em [mergeSort.h]
    time(&t_end);
    tempo = difftime(t_end, t_start);
    
    print(vetor);
    printf("O tempo de ordenaçao: %.1fs\n", tempo); 
}
