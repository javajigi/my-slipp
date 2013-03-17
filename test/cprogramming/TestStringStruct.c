#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cprogramming/StringStruct.c"
#include "unity.h"

#define TEST_DATA "Test Data"
#define ALLOC_SIZE 10

struct string_pair *str_pair;

void setUp(void) {
	str_pair = alloc_str_pair(ALLOC_SIZE);
}

void tearDown(void) {
	free_str_pair(str_pair);
}

void test_str_pair_alloc(void) {
	strcpy(str_pair->target,TEST_DATA);
	TEST_ASSERT_EQUAL(0, strcmp(str_pair->target, TEST_DATA));
	// TEST_ASSERT_NOT_EQUAL(target_result, str_pair->target);
}

void test_str_pair_str_length(void) {
	int length = length_str_pair_source(TEST_DATA);
	TEST_ASSERT_EQUAL(9, length);
}

void test_copy_str_pair(void) {
	str_pair->source = TEST_DATA;
	copy_str_pair(str_pair);
	TEST_ASSERT_EQUAL(0, strcmp(str_pair->target, TEST_DATA));
}

void test_copy_str_pair_reverse(void) {
	str_pair->source = TEST_DATA;
	copy_str_pair_reverse(str_pair);
	TEST_ASSERT_EQUAL(0, strcmp(str_pair->target, "ataD tseT"));
}
