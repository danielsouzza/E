#ifndef selectionSort
#define selectionSort

// Troca de elementos
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Ordenação por seleção direta
void selectionSort(int array[], int size) {
	for (int i = 0; i < size; i++) {
		int least = i;
		for (int j = i+1; j < size; j++) {
			if (array[least] > array[j]) {
				least = j;
			}
		}
		swap(&array[i], &array[least]);
	}
}

// Computar tempo de execução do SelectionSort
double timeSelection(int array[], int size) {
	clock_t Ticks[2];				// Tempo inicial e final
	Ticks[0] = clock(); 			// Início
	selectionSort(array, size);		// Execução
	Ticks[1] = clock();				// Fim
	return (double) (Ticks[1] - Ticks[0]) / (double) CLOCKS_PER_SEC;
}

#endif
