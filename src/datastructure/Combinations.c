#include <stdio.h>

void swap(char *i, char *j) {
	char temp = *i;
	*i = *j;
	*j = temp;
}

void combinations_one(char *values, int n, int r, int original_n) {
	for (int i = 0; i <= n - 1; i++) {
		if (r == 1) {
			printf(" %c ", values[i]);
			printf(", %c \n", values[original_n-1]);
		}
	}
}

void combinations_two(char *values, int n, int r, int original_n) {
	if (original_n == 1) {
		return;
	}
	combinations_one(values, n - 1, r - 1, original_n);
	combinations_two(values, n - 1, r, original_n - 1);
}

void combinations_three(char *values, int n, int r, int original_n) {
	if (original_n == 1) {
		return;
	}
	combinations_two(values, n - 1, r - 1, original_n);
	combinations_three(values, n - 1, r, original_n - 1);
}

