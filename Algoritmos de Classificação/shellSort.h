#include <time.h>

void shellSort(int *vetor, int tamanho)
{
    int i, j, h, aux;

    for (h = 1; h < tamanho; h = 3 * h + 1)
        ;
    while (h > 0)
    {
        h = (h - 1) / 3;
        for (j = h; j < tamanho; j++)
        {
            aux = vetor[j];
            i = j - h;

            while (i >= 0 && vetor[i] > aux)
            {
                vetor[i + h] = vetor[i];
                i = i - h;
            }
            vetor[i + h] = aux;
        }
    }
}

double TimeShell(int vetor[], int tamanho)
{
    clock_t Ticks[2];
    Ticks[0] = clock();
    shellSort(vetor, tamanho);
    Ticks[1] = clock();
    return (double)(Ticks[1] - Ticks[0]) / (double)CLOCKS_PER_SEC;
}