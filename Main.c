#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mergeSort.h"
#include "quickSort.h"
#include "bubbleSort.h"

const int t = 80000; // Tamanho do vetor

// Gerar um vetor aleatorio
void generateVectors(int vetor1[], int vetor2[], int vetor3[],
int vetor4[],int vetor5[],int vetor6[],int vetor7[])
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

// Função para imprimir
void print(int vetor[])
{
    for (int i = 0; i < t; i++)
    {
        printf("[%d] ", vetor[i]);
    }
    printf("\n");
}


void main()
{
    double tempo[3]; // Armazena o tempo da ordenação
    int vetor1[t],vetor2[t], vetor3[t], vetor4[t], vetor5[t],vetor6[t], vetor7[t];
    int end = t - 1;
    generateVectors(vetor1, vetor2, vetor3, vetor4, vetor5, vetor6, vetor7);
 
    // Merge Sort
    tempo[0] = TimeMerge(vetor1, end);
    tempo[1] = TimeMerge(vetor1, end);
    invertVector(vetor1);
    tempo[2] = TimeMerge(vetor1, end);

    printf("MergeSort no caso médio.: %fs\n", tempo[0]);  
    printf("MergeSort no melhor caso: %fs\n", tempo[1]);
    printf("MergeSort no pior caso..: %fs\n\n", tempo[2]);


    // Bubblesort
    tempo[0] = TimeBubble(vetor2, t);
    tempo[1] = TimeBubble(vetor2, t);
    invertVector(vetor2);
    tempo[2] = TimeBubble(vetor2, t);

    printf("BubbleSort no caso médio.: %fs\n", tempo[0]);  
    printf("BubbleSort no melhor caso: %fs\n", tempo[1]);
    printf("BubbleSort no pior caso..: %fs\n\n", tempo[2]);
    

    // QuickSort
    tempo[0] = TimeQuick(vetor3, end);
    tempo[1] = TimeQuick(vetor3, end);
    invertVector(vetor3);
    tempo[2] = TimeQuick(vetor3, end);

    printf("QuickSort no caso médio.: %fs\n", tempo[0]);  
    printf("QuickSort no melhor caso: %fs\n", tempo[1]);
    printf("QuickSort no pior caso..: %fs\n\n", tempo[2]);
}


