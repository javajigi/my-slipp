#include <stdio.h>

void swap(char *i, char *j) {
	char temp = *i;
	*i = *j;
	*j = temp;
}

void printCombinations(char *values, int *currentPosition, int start, int end) {
	printf("%d \n", *currentPosition);

	for (int i = start; i <= end; i++) {
		printf("%c,", values[i]);
		printf("     ");
		if (i == end) {
			printf("\n");
		}
	}
}

void combinations(char *values, int *currentPosition, int start, int end) {
	int j;
	if (start == end) {
		printCombinations(values, currentPosition, start, end);
		*currentPosition = *currentPosition + 1;
		return;
	} else {
		for (j = start; j <= end; j++) {
			swap(&values[start], &values[j]);
			printCombinations(values, currentPosition, start, end);
			combinations(values, currentPosition, start+1, end);
			swap(&values[start], &values[j]);
		}
	}
}
