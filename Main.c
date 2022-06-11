#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "mergeSort.h"

const int t = 80000;

void print(int vetor[], int size)
{
    for(int i = 0; i <= size; i++){
        printf("[%d] ", vetor[i]);
    }
    printf("\n");
}

void generateVector(int * vetor){
    srand(time(NULL));
    for (int i = 0; i < t; i++)
    {
        vetor[i] = rand() % 80000; 
        printf("%d ", vetor[i]);
    }
    
}

void main()
{
    int vetor[t];
    int end;
    generateVector(vetor);
    
    end = sizeof(vetor) / sizeof(int) - 1;
    print(vetor, end);
    mergeSort(vetor, 0, end);
    print(vetor, end);
}