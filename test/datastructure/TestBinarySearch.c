#include <stdio.h>

#include "datastructure/BinarySearch.c"
#include "unity.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_find_middle_index(void) {
	int middle_index = find_middle_index(0, 9);
	TEST_ASSERT_EQUAL(5, middle_index);

	middle_index = find_middle_index(2, 6);
	TEST_ASSERT_EQUAL(4, middle_index);
}

void test_search_middle_index(void) {
	int values[] = { 1, 2, 3, 4, 5 };
	int search_num = 3;

	int result = search_index(values, search_num, 0, 4);
	TEST_ASSERT_EQUAL(2, result);
}

void test_search_top_index(void) {
	int values[] = { 1, 2, 3, 4, 5 };
	int search_num = 5;

	int result = search_index(values, search_num, 0, 4);
	TEST_ASSERT_EQUAL(4, result);
}

void test_search_bottom_index(void) {
	int values[] = { 1, 2, 3, 4, 5 };
	int search_num = 1;

	int result = search_index(values, search_num, 0, 4);
	TEST_ASSERT_EQUAL(0, result);
}
