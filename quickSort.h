#include <time.h>
#include <stdlib.h>

//Ordenação por troca ou Exchange Sort
//Dividir para conquistar

// void swap(int *ii, int *jj)
// {
//     int aux = *ii;
//     *ii = *jj;
//     *jj = aux;
// }//troca o elemento

int particionar (int vet[], int inicial, int final)
{
    int pivo = vet[final]; // pivô, último elemento
    int i = (inicial - 1); // índice do menor elemento
 
    for (int j = inicial; j <= final - 1; j++)
    {
        if (vet[j] < pivo)
        {
            i++; // incrementa no índice de menor elemento
            swap(&vet[i], &vet[j]);
        }
    }
    swap(&vet[i + 1], &vet[final]);
    return (i + 1);
}

void quickSort(int vet[], int inicial, int final)
{
    if (inicial < final)
    {
        int pi = particionar(vet, inicial, final);

        quickSort(vet, inicial, pi - 1);
        quickSort(vet, pi + 1, final);
    }
}

double TimeQuick(int vetor[], int size)
{
    time_t t_start; // t_start pega o tempo inicial
    time_t t_end;   // t_end pega o tempo final

    t_start = time(NULL);
    quickSort(vetor,0, size); // Chama o algoritmo que está em [mergeSort.h]
    t_end = time(NULL);

    return difftime(t_end,t_start);
}

/*
 inicial -> 0
 final -> tamanho do vetor - 1 (80000 -1)

 quickSort(vetor, 0, TAM - 1);
*/