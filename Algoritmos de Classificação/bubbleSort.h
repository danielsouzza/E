#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


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
    clock_t Ticks[2];
    Ticks[0] = clock();  // t_end pega o tempo final
    bubbleSort(vetor, size); // Chama o algoritmo que está em [mergeSort.h]
    Ticks[1] = clock();

    return (double)(Ticks[1] - Ticks[0]) / (double)CLOCKS_PER_SEC;
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
