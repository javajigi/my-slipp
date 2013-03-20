#include <stdio.h>

void swap(int *i, int *j) {
	int temp = *i;
	*i = *j;
	*j = temp;
}

int minimun_index(int *values, int offset, int length) {
	int index = offset;
	int minimun_value = values[offset];
	for(int i=offset+1; i < length; i++) {
		if (values[i] < minimun_value) {
			index = i;
			minimun_value = values[i];
		}
	}

	return index;
}

void sort(int *values, int n) {
	int offset, min;
	for (offset = 0; offset < n-1; offset++) {
		min = minimun_index(values, offset, n);
		printf("minimum index : %d, value : %d\n", min, values[min]);
		swap(&values[offset], &values[min]);
	}
}
