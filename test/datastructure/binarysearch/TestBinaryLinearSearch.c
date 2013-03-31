#include <stdio.h>

#include "datastructure/binarysearch/BinarySearch.c"
#include "unity.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_search_start_index_one_element_when_search_value(void) {
	int values[] = { 1 };
	int right = 0;
	int search_num = 1;

	int result = search_start_index(values, search_num, 0, right, -1);
	TEST_ASSERT_EQUAL(0, result);
}

void test_search_start_index_one_element_when_no_search_value(void) {
	int values[] = { 1 };
	int right = 0;
	int search_num = 2;

	int result = search_start_index(values, search_num, 0, right, -1);
	TEST_ASSERT_EQUAL(-1, result);
}

void test_search_binary_index_two_element_when_search_value(void) {
	int values[] = { 1, 1 };
	int right = 1;
	int search_num = 1;

	int start_index = search_start_index(values, search_num, 0, right, -1);
	TEST_ASSERT_EQUAL(0, start_index);

	int end_index = search_end_index(values, search_num, 0, right, -1);
	TEST_ASSERT_EQUAL(1, end_index);
}

void test_search_binary_index_two_element_when_no_search_value(void) {
	int values[] = { 1, 1 };
	int right = 1;
	int search_num = 2;

	int start_index = search_start_index(values, search_num, 0, right, -1);
	TEST_ASSERT_EQUAL(-1, start_index);
}

void test_search_binary_index_three_element_when_search_value(void) {
	int values[] = { 1, 2, 2 };
	int right = 2;
	int search_num = 2;

	int start_index = search_start_index(values, search_num, 0, right, -1);
	TEST_ASSERT_EQUAL(1, start_index);

	int end_index = search_end_index(values, search_num, 0, right, -1);
	TEST_ASSERT_EQUAL(2, end_index);
}

void test_search_binary_index_three_element_when_no_search_value(void) {
	int values[] = { 1, 2, 2 };
	int right = 2;
	int search_num = 3;

	int start_index = search_start_index(values, search_num, 0, right, -1);
	TEST_ASSERT_EQUAL(-1, start_index);

	int end_index = search_end_index(values, search_num, 0, right, -1);
	TEST_ASSERT_EQUAL(-1, end_index);
}

void test_search_binary_index_five_element_when_search_value(void) {
	int values[] = { 1, 2, 2, 2, 3 };
	int right = 4;
	int search_num = 2;

	int start_index = search_start_index(values, search_num, 0, right, -1);
	TEST_ASSERT_EQUAL(1, start_index);

	int end_index = search_end_index(values, search_num, 0, right, -1);
	TEST_ASSERT_EQUAL(3, end_index);
}

void test_count_match_value(void) {
	int values[] = { 1, 2, 2, 2, 2, 4, 5 };
	int length = 6;
	int search_num = 2;

	int result = count_match_value(values, search_num, length);
	TEST_ASSERT_EQUAL(4, result);

	search_num = 3;
	result = count_match_value(values, search_num, length);
	TEST_ASSERT_EQUAL(0, result);
}
