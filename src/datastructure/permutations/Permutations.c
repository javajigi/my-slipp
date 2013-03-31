#include <stdio.h>

void swap(char *i, char *j) {
	char temp = *i;
	*i = *j;
	*j = temp;
}

void perm(char *values, int start, int end) {
	int j;
	if (start == end) {
		for (j = 0; j <= end; j++) {
			printf("%c,", values[j]);
			printf("     ");
			if (j == end) {
				printf("\n");
			}
		}
	} else {
		for (j = start; j <= end; j++) {
			swap(&values[start], &values[j]);
			perm(values, start+1, end);
			swap(&values[start], &values[j]);
		}
	}
}
