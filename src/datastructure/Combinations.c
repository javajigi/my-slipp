#include <stdio.h>

void swap(char *i, char *j) {
	char temp = *i;
	*i = *j;
	*j = temp;
}

void print_combinations(char *values, int start, int end) {
	for(int i=start; i <= end; i++) {
		printf(" %c", values[i]);
		if (i == end) {
			printf(" \n");
		} else {
			printf(", ");
		}
	}
}

void combinations_two(char *values, int n, int r) {
	for(int i=0; i<=r;i++) {
		swap(values, values + i);
		print_combinations(values, r-1, r);
		swap(values + i, values);
	}
}

void combinations_three(char *values, int n, int r) {
	for(int i=0; i<=r;i++) {
		swap(values, values + i);
		print_combinations(values, r-2, r);
		swap(values + i, values);
	}
}

void combinations_four(char *values, int n, int r) {
	for(int i=0; i<=r;i++) {
		swap(values, values + i);
		print_combinations(values, r-3, r);
		swap(values + i, values);
	}
}

void combinations(char *values, int start, int end) {
}
