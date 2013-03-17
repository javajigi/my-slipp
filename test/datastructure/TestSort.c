#include <stdio.h>

#include "datastructure/Sort.c"
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

