#include <time.h>

void insercaoDireta(int *vetor, int tamanho)
{
    int i, j, aux;

    for (j = 1; j < tamanho; j++)
    {
        aux = vetor[j];
        i = j - 1;
        while ((i >= 0 && vetor[i] > aux))
        {
            vetor[i + 1] = vetor[i];
            i = i - 1;
        }
        vetor[i + 1] = aux;
    }
}

double TimeInsertion(int vetor[], int tamanho)
{
    clock_t Ticks[2];
    Ticks[0] = clock();
    insercaoDireta(vetor, tamanho);
    Ticks[1] = clock();

    return (double)(Ticks[1] - Ticks[0]) / (double)CLOCKS_PER_SEC;
}
