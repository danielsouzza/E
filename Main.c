#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mergeSort.h"
#include "bubbleSort.h"

const int t = 80000; // Tamanho do vetor

// Função para printar
void print(int vetor[])
{
    for (int i = 0; i < t; i++)
    {
        printf("[%d] ", vetor[i]);
    }
    printf("\n");
}

// Gerar um vetor aleatorio
void generateVectores(int vetor1[], int vetor2[], int vetor3[],int vetor4[],int vetor5[],int vetor6[],int vetor7[])
{
    srand(time(NULL)); // Gera uma semente comforme o tempo
    for (int i = 0; i < t; i++)
    {
        int aux = rand() % t;
        vetor1[i] = aux;
        vetor2[i] = aux;
        vetor3[i] = aux;
        vetor4[i] = aux;
        vetor5[i] = aux;
        vetor6[i] = aux;
        vetor7[i] = aux;
        

    }
}

// Inverte o vetor
void invertVector(int vetor[])
{
    int mid = t / 2;
    for (int i = 0, j = t - 1; i < mid; i++, j--)
    {
        int aux = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = aux;
    }
}

double casosMerge(int vetor[], int end)
{
    time_t t_start; // t_start pega o tempo inicial
    time_t t_end;   // t_end pega o tempo final

    t_start = time(NULL);
    mergeSort(vetor, 0, end); // Chama o algoritmo que está em [mergeSort.h]
    t_end = time(NULL);

    return difftime(t_end,t_start);
}

double casoBubble(int vetor[])
{
    time_t t_start; // t_start pega o tempo inicial
    time_t t_end;   // t_end pega o tempo final

    t_start = time(NULL);
    bubbleSort(vetor, t); // Chama o algoritmo que está em [mergeSort.h]
    t_end = time(NULL);

    return difftime(t_end,t_start);
}

void main()
{
    double tempo[3]; // Armazena o tempo da ordenação

    int vetor1[t],vetor2[t], vetor3[t], vetor4[t], vetor5[t],vetor6[t], vetor7[t];
    int end = t - 1;
    generateVectores(vetor1,vetor2,vetor3, vetor4, vetor5, vetor6, vetor7);

    // Merge Sort
    tempo[0] = casosMerge(vetor1, end);
    tempo[1] = casosMerge(vetor1, end);
    invertVector(vetor1);
    tempo[2] = casosMerge(vetor1, end);


    printf("MergeSort no caso médio.: %fs\n", tempo[0]);  
    printf("MergeSort no melhor caso: %fs\n", tempo[1]);
    printf("MergeSort no pior caso..: %fs\n", tempo[2]);

    // Bubblesort
    tempo[0] = casoBubble(vetor2);
    tempo[1] = casoBubble(vetor2);
    invertVector(vetor1);
    tempo[2] = casoBubble(vetor2);

    printf("BubbleSort caso médio.: %fs\n", tempo[0]);  
    printf("BubbleSort melhor caso: %fs\n", tempo[1]);
    printf("BubbleSort pior caso..: %fs\n", tempo[2]);
}


