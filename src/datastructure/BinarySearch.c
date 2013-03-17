#include <stdio.h>

int find_middle_index(int start, int end) {
	int middle = (end - start) / 2;
	return start + middle;
}

int search_value(int values[], int search_num, int index) {
	int value = values[index];
	if (value == search_num) {
		return 0;
	}

	if (value < search_num) {
		return 1;
	}

	return -1;
}

int search_index(int values[], int start, int end, int search_num) {
	int middle_index = find_middle_index(start, end);
	int result = search_value(values, search_num, middle_index);
	if (result == 0) {
		return middle_index;
	}

	if ( start == end ) {
		return -1;
	}

	if (result == 1) {
		return search_index(values, middle_index + 1, end, search_num);
	}

	if (result == -1) {
		return search_index(values, start, middle_index-1, search_num);
	}

	return -1;
}
