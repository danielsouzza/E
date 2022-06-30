#include "util.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "heapSort.h"
#include "quickSort.h"
#include "shellSort.h"
#include "mergeSort.h"
#include "bubbleSort.h"
#include "selectionSort.h"
#include "insertionSort.h"

const int t = 120000; // Tamanho do vetor

// Gerar um vetor aleatorio
void generateVectors(int vetor1[], int vetor2[], int vetor3[],
int vetor4[],int vetor5[],int vetor6[],int vetor7[])
{
    srand(time(NULL)); // Gera uma semente comforme o tempo
    for (int i = 0; i < t; i++)
    {
        int aux = rand() % t;
        vetor1[i] = aux;
        vetor2[i] = aux;
        vetor3[i] = aux;
        vetor4[i] = aux;
        vetor5[i] = aux;
        vetor6[i] = aux;
        vetor7[i] = aux;
    }
}

// Inverte o vetor
void invertVector(int vetor[])
{
    int mid = t / 2;
    for (int i = 0, j = t - 1; i < mid; i++, j--)
    {
        int aux = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = aux;
    }
}

// imprime na tela os dados do arquivo 
void printResultados(FILE *dados)
{
    dados = fopen("Tempo de ordenação.txt", "r");
    char c;
    c = fgetc(dados);
    while (c != EOF)
    {
        printf("%c", c);
        c = fgetc(dados);
        
    }
    fclose(dados);
}

// Coloca os dados no arquivo
void fprint(FILE * arq, double * tempo, char str[])
{
    fprintf(arq,"%-16s ", str);
    fprintf(arq,"| %10f ", tempo[0]);  
    fprintf(arq,"| %11f ", tempo[1]);
    fprintf(arq,"| %11f \n", tempo[2]);
}

void main()
{
    FILE *dados = fopen("Tempo de ordenação.txt", "w"); 
    double tempo[3]; // Armazena o tempo da ordenação
    int vetor1[t],vetor2[t], vetor3[t], vetor4[t], vetor5[t],vetor6[t], vetor7[t];
    int end = t - 1;
    generateVectors(vetor1, vetor2, vetor3, vetor4, vetor5, vetor6, vetor7);
    
    if(dados == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    fprintf(dados,"%-16s | %11s | %11s | %11s\n", "Algoritmos", "Caso médio","Melhor caso","Pior caso");
    fprintf(dados,"=========================================================\n");

    // Bubblesort
    tempo[0] = TimeBubble(vetor1, t);
    tempo[1] = TimeBubble(vetor1, t);
    invertVector(vetor1);
    tempo[2] = TimeBubble(vetor1, t);
    char Bubble[] = "Bubblesort";
    fprint(dados, tempo, Bubble);
 
    // QuickSort
    tempo[0] = TimeQuick(vetor2, end);
    tempo[1] = TimeQuick(vetor2, end);
    invertVector(vetor2);
    tempo[2] = TimeQuick(vetor2, end);

    char Quick[] = "QuickSort";
    fprint(dados, tempo, Quick);

	// SelectionSort
	tempo[0] = TimeSelection(vetor3, t);
	tempo[1] = TimeSelection(vetor3, t);
	invertVector(vetor3);
	tempo[2] = TimeSelection(vetor3, t);

    char Selection[] = "SelectionSort";
    fprint(dados, tempo, Selection);

	// HeapSort
	tempo[0] = TimeHeap(vetor4, t);
	tempo[1] = TimeHeap(vetor4, t);
	invertVector(vetor4);
	tempo[2] = TimeHeap(vetor4, t);
	
	char Heap[] = "HeapSort";
    fprint(dados, tempo, Heap);

    // InsertionSort
    tempo[1] = TimeInsertion(vetor5, t);
    tempo[0] = TimeInsertion(vetor5, t);
    invertVector(vetor5);
    tempo[2] = TimeInsertion(vetor5, t);

    char Insertion[] = "InsertionSort";
    fprint(dados, tempo, Insertion);

    // ShellSort
    tempo[1] = TimeInsertion(vetor6, t);
    tempo[0] = TimeInsertion(vetor6, t);
    invertVector(vetor6);
    tempo[2] = TimeInsertion(vetor6, t);
 
    char Shell[] = "ShellSort";
    fprint(dados, tempo, Shell);

    // Merge Sort
    tempo[0] = TimeMerge(vetor7, end);
    tempo[1] = TimeMerge(vetor7, end);
    invertVector(vetor7);
    tempo[2] = TimeMerge(vetor7, end); 

    char Merge[] = "MergeSort";
    fprint(dados, tempo, Merge);

    fclose(dados);
    printResultados(dados);
}