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

#endif
