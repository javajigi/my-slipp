#include <stdio.h>

void swap(int *i, int *j) {
	int temp = *i;
	*i = *j;
	*j = temp;
}

void sort(int values[], int n) {
	int i, j, min;
	for (i = 0; i < n-1; i++) {
		min = i;
		for (j = i + 1; j < n; j++) {
			if (values[min] > values[j]) {
				swap(&values[i], &values[j]);
				printf("minimum %d, value : %d\n", min, values[min]);
			}
		}
	}
}
