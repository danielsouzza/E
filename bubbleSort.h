#include <stdlib.h>
#include <time.h>
#include<stdbool.h>

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

double TimeBubble(int vetor[], int size)
{
    time_t t_start; // t_start pega o tempo inicial
    time_t t_end;   // t_end pega o tempo final

    t_start = time(NULL);
    bubbleSort(vetor, size); // Chama o algoritmo que está em [mergeSort.h]
    t_end = time(NULL);

    return difftime(t_end,t_start);
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