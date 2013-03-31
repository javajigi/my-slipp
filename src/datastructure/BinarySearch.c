#include <stdio.h>

int find_middle_index(int start, int end) {
	int middle = (end - start + 1) / 2;
	printf(" middle : %d\n", middle);
	return start + middle;
}

int search_index(int *values, int search_num, int left, int right) {
	int left_index = left;
	int right_index = right;

	while (left_index <= right_index) {
		int middle_index = find_middle_index(left_index, right_index);
		int value = values[middle_index];

		if (search_num == value) {
			return middle_index;
		}

		if (search_num > value) {
			left_index = middle_index + 1;
			continue;
		}

		if (search_num < value) {
			right_index = middle_index - 1;
			continue;
		}
	}

	return -1;
}

int search_start_index(int *values, int search_num, int left, int right, int searched_index) {
	int first_search_index = search_index(values, search_num, 0, right);
	printf(" first search index : %d\n", first_search_index);

	if (first_search_index == -1) {
		return searched_index;
	}

	if (right == 0 ) {
		return first_search_index;
	}

	return search_start_index(values, search_num, 0, first_search_index - 1, first_search_index);
}

int search_end_index(int *values, int search_num, int left, int right, int searched_value) {
	int first_search_index = search_index(values, search_num, left, right);
	printf(" first search index : %d\n", first_search_index);

	if (first_search_index == -1) {
		return searched_value;
	}

	if (left == right) {
		return first_search_index;
	}

	return search_index(values, search_num, first_search_index, right);
}

int count_match_value(int *values, int search_num, int length) {
	int start_index = search_start_index(values, search_num, 0, length, -1);
	int end_index = search_end_index(values, search_num, 0, length, -1);

	if (start_index == -1 || end_index == -1) {
		return 0;
	}

	return (end_index - start_index) + 1;
}
