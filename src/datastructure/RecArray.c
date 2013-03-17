#include <stdio.h>

void swap(char *i, char *j) {
	char temp = *i;
	*i = *j;
	*j = temp;
}

void perm(char *values, int i, int n) {
	int j;
	if (i == n) {
		for (j = 0; j < n; j++) {
			printf("%c,", values[j]);
			printf("     ");
			if (n == j+1) {
				printf("\n");
			}
		}
	} else {
		for (j = i; j < n; j++) {
			swap(&values[i], &values[j]);
			perm(values, i+1, n);
			swap(&values[i], &values[j]);
		}
	}
}
