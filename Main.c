#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mergeSort.h"

const int t = 80000; // Tamanho do vetor

// Função para printar
void print(int vetor[], int size)
{
    for(int i = 0; i <= size; i++){
        printf("[%d] ", vetor[i]);
    }
    printf("\n");
}

// Gerar um vetor aleatorio
void generateVector(int * vetor){
    srand(time(NULL)); // Gera uma semente comforme o tempo
    for (int i = 0; i < t; i++)
    {
        vetor[i] = rand() % t; 
    }
}

void main()
{
    double tempo; // Armazena o tempo da ordenação
    time_t t_start;// t_start pega o tempo inicial
    time_t t_end; // t_end pega o tempo final

    int vetor[t];
    int end = t -1;
    generateVector(vetor);

    // Merge Sort
    print(vetor, end);
    t_start = time(NULL); 
    mergeSort(vetor, 0, end); // Chama o algoritmo que está em [mergeSort.h]
    t_end = time(NULL);
    tempo = difftime(t_end, t_start);
    print(vetor, end);
    printf("O tempo de ordenaçao: %fs\n", tempo); 
}