#include <stdio.h>

#include "datastructure/BinarySearch.c"
#include "unity.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_find_middle_index(void) {
	int middle_index = find_middle_index(0, 10);
	TEST_ASSERT_EQUAL(5, middle_index);

	middle_index = find_middle_index(2, 8);
	TEST_ASSERT_EQUAL(5, middle_index);
}

void test_search_exact_value(void) {
	int values[] = { 1, 2, 3, 4, 5 };
	int search_num = 3;
	int index = 2;
	int result = search_value(values, search_num, index);
	TEST_ASSERT_EQUAL(0, result);
}

void test_search_bottom_value(void) {
	int values[] = { 1, 2, 3, 4, 5 };
	int search_num = 3;
	int index = 1;
	int result = search_value(values, search_num, index);
	TEST_ASSERT_EQUAL(1, result);
}

void test_search_top_value(void) {
	int values[] = { 1, 2, 3, 4, 5 };
	int search_num = 3;
	int index = 3;
	int result = search_value(values, search_num, index);
	TEST_ASSERT_EQUAL(-1, result);
}

void test_search_index(void) {
	int values[] = { 1, 2, 3, 4, 5 };
	int search_num = 3;

	int result = search_index(values, 0, 4, search_num);
	TEST_ASSERT_EQUAL(2, result);
}

void test_search_top_index(void) {
	int values[] = { 1, 2, 3, 4, 5 };
	int search_num = 5;

	int result = search_index(values, 0, 4, search_num);
	TEST_ASSERT_EQUAL(4, result);
}

void test_search_bottom_index(void) {
	int values[] = { 1, 2, 3, 4, 5 };
	int search_num = 1;

	int result = search_index(values, 0, 4, search_num);
	TEST_ASSERT_EQUAL(0, result);
}

void test_is_not_search_value(void) {
	int values[] = { 1, 2, 6, 7, 8 };
	int search_num = 3;

	int result = search_index(values, 0, 4, search_num);
	TEST_ASSERT_EQUAL(-1, result);
}
