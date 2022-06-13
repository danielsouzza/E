#include<stdbool.h>
#include<stdlib.h>

void swap(int *j1, int *j2)
{
    int aux = *j1;
    *j1 = *j2;
    *j2 = aux;
}

void bubbleSort(int vetor[], int tamanho)
{
    int i, j;
    bool swapped;
    for (i = 0; i < tamanho - 1; i++)
    {
        swapped = false;
        for (j = 0; j < tamanho - i - 1; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                swap(&vetor[j], &vetor[j + 1]);
                swapped = true;
            }
        }
    }
}

/*
vetor ordenado
vetor ordenado invertido

int aux ;
    bool swapped = true;
    do{
        swapped = false;
        for (int i = 0; i < (tamanho - 1); i++)
        {
            if (vetor[i] > vetor[i+1])
            {
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
                swapped = true;
            }
        }
    } while (swapped);
*/