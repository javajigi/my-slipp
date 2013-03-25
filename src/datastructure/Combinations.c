#include <stdio.h>

void swap(char *i, char *j) {
	char temp = *i;
	*i = *j;
	*j = temp;
}

void print_combinations(char *values, int start, int end) {
	for (int i = start; i <= end; i++) {
		printf(" %c", values[i]);
		if (i == end) {
			printf(" \n");
		} else {
			printf(", ");
		}
	}
}

void combinations_two(char *values, int n, int r) {
	for (int start = 0; start <= n - r + 1; start++) {
		for (int i = start; i <= n - r; i++) {
			printf(" %c, %c\n", values[start], values[i + 1]);
		}
	}
}

void combinations_three(char *values, int n, int r) {
	for (int i = 0; i < n; i++) {
		swap(values, values + i);
		print_combinations(values, 1, r);
		swap(values + i, values);
	}
}

void combinations_four(char *values, int n, int r) {
	for (int i = 0; i <= r; i++) {
		swap(values, values + i);
		print_combinations(values, 1, r);
		swap(values + i, values);
	}
}
