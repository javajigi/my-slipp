#include <stdio.h>

int find_middle_index(int start, int end) {
	int middle = (end - start) / 2;
	return start + middle;
}

int search_index(int *values, int length, int search_num) {
	int left_index = 0;
	int right_index = length - 1;

	while (left_index <= right_index) {
		int middle_index = find_middle_index(left_index, right_index);
		int value = values[middle_index];

		if (search_num > value) {
			left_index = middle_index + 1;
			continue;
		}

		if (search_num == value) {
			return middle_index;
		}

		if (search_num < value) {
			right_index = middle_index - 1;
			continue;
		}
	}

	return -1;
}

int search_start_index(int *values, int length, int search_num) {
	int first_search_index = search_index(values, length, search_num);

	if (first_search_index == -1) {
		return -1;
	}

	for (int i=first_search_index-1; i > -1; i--) {
		if (search_num != values[i]) {
			return i+1;
		}
	}

	return -1;
}

int search_end_index(int *values, int length, int search_num) {
	int first_search_index = search_index(values, length, search_num);

	if (first_search_index == -1) {
		return -1;
	}

	for (int i=first_search_index+1; i < length; i++) {
		if (search_num != values[i]) {
			return i-1;
		}
	}

	return -1;
}

int count_match_value(int *values, int length, int search_num) {
	int start_index = search_start_index(values, length, search_num);
	int end_index = search_end_index(values, length, search_num);

	if (start_index == -1 || end_index == -1) {
		return 0;
	}

	return (end_index-start_index) + 1;
}
