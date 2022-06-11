#include <stdio.h>
#include <math.h>
#include <stdlib.h>


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
                if(vetor[p1] < vetor[p2])
                {
                    temp[i] = vetor[p1++];
                }else{
                    temp[i] = vetor[p2++];
                }

                if(p1 > mid) end1 = 1;
                if(p2 > end) end2 = 1;
            }else{
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

void print(int vetor[], int size)
{
    for(int i = 0; i <= size; i++){
        printf("[%d] ", vetor[i]);
    }
    printf("\n");
}

void main()
{
    int vetor[] = {3, 4, 9, 2, 5, 8, 2, 1, 7, 4, 6, 2, 9, 8, 5, 1};
    int end = sizeof(vetor) / sizeof(int) - 1;
    print(vetor, end);
    mergeSort(vetor, 0, end);
    print(vetor, end);
}