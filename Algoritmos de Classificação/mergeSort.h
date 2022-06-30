#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


// Função para fazer a ordenação [Conquistar]
void merge(int * vetor, int start, int mid, int end)
{  
    int * temp, p1, p2, size, i , j, k;
    int end1 = 0, end2 = 0;
    size = end - start + 1;
    p1 = start;
    p2 = mid + 1;
    temp = (int*) malloc(size * sizeof(int));
    if(temp != NULL)
    {
        for(i=0; i < size; i++)
        {
            if(!end1 && !end2)
            {
                // Comparar e colocar de forma ordenada no vetor temporário [temp]
                if(vetor[p1] < vetor[p2])
                {
                    temp[i] = vetor[p1++];
                }else{
                    temp[i] = vetor[p2++];
                }

                // Verificar se o vetor chegou no fim
                if(p1 > mid) end1 = 1; 
                if(p2 > end) end2 = 1;
            }else{
                // Copiar o elemento restante para temp
                if(!end1)
                {
                    temp[i] = vetor[p1++];
                }else{
                    temp[i] = vetor[p2++];
                }
            }
        }
        for(j=0, k=start; j < size;j++, k++) vetor[k] = temp[j];
    }
    free(temp);
}

//  Função para fazer a divisão do vetor de forma recursiva
void mergeSort(int * vetor, int start, int end)
{
    int mid;
    if(start < end)
    {

        mid = floor((start + end) / 2);
        mergeSort(vetor,start, mid);
        mergeSort(vetor,mid+1, end);
        merge(vetor, start, mid, end);

    }
}

double TimeMerge(int vetor[], int end)
{
    clock_t Ticks[2];
    Ticks[0] = clock();  // t_end pega o tempo final
    mergeSort(vetor, 0, end); // Chama o algoritmo que está em [mergeSort.h]
    Ticks[1] = clock();

    return (double)(Ticks[1] - Ticks[0]) / (double)CLOCKS_PER_SEC;
}