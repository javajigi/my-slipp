#include <stdio.h>

#include "datastructure/BinarySearch.c"
#include "unity.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_search_start_index(void) {
	int values[] = { 1, 2, 2, 2, 2, 4, 5 };
	int search_num = 2;

	int result = search_start_index(values, 7, search_num);
	TEST_ASSERT_EQUAL(1, result);

	search_num = 3;
	result = search_start_index(values, 7, search_num);
	TEST_ASSERT_EQUAL(-1, result);
}

void test_search_end_index(void) {
	int values[] = { 1, 2, 2, 2, 2, 4, 5 };
	int search_num = 2;

	int result = search_end_index(values, 7, search_num);
	TEST_ASSERT_EQUAL(4, result);
}

void test_count_match_value(void) {
	int values[] = { 1, 2, 2, 2, 2, 4, 5 };
	int search_num = 2;
	int result = count_match_value(values, 7, search_num);
	TEST_ASSERT_EQUAL(4, result);

	search_num = 3;
	result = count_match_value(values, 7, search_num);
	TEST_ASSERT_EQUAL(0, result);
}
