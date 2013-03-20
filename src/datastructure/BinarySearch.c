#include <stdio.h>

int find_middle_index(int start, int end) {
	int middle = (end - start) / 2;
	return start + middle;
}

int search_value(int *values, int search_num, int index) {
	int value = values[index];
	if (value == search_num) {
		return 0;
	}

	if (value < search_num) {
		return 1;
	}

	return -1;
}

int search_index(int *values, int length, int search_num) {
	int left_index = 0;
	int right_index = length - 1;

	while (left_index <= right_index) {
		int middle_index = find_middle_index(left_index, right_index);
		int result = search_value(values, search_num, middle_index);

		if (result == 1) {
			left_index = middle_index + 1;
		}

		if (result == 0) {
			return middle_index;
		}

		if (result == -1) {
			right_index = middle_index - 1;
		}
	}

	return -1;
}
