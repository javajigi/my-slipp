#include <stdio.h>

#include "datastructure/SelectionSort.c"
#include "unity.h"

void setUp(void) {
	printf("setUp\n");
}

void tearDown(void) {
	printf("tearDown\n");
}

void test_swap(void) {
	int i = 1;
	int j = 2;

	swap(&i, &j);
	TEST_ASSERT_EQUAL(2, i);
	TEST_ASSERT_EQUAL(1, j);
}

void test_minimun_index(void) {
	int values[] = { 2, 1, 3 };
	int index = minimun_index(values, 0, 3);
	TEST_ASSERT_EQUAL(1, index);

	int values2[] = {3, 2, 1};
	index = minimun_index(values2, 0, 3);
	TEST_ASSERT_EQUAL(2, index);
}

void test_sort(void) {
	int values[] = { 4, 5, 2, 1, 3 };
	int length = 5;
	sort(values, length);
	TEST_ASSERT_EQUAL(1, values[0]);

	int i;
	for (i = 0; i < length; i++) {
		printf("value : %d\n", values[i]);
	}
}

