#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cprogramming/StringStruct.c"
#include "unity.h"

#define TEST_DATA "Test Data"
#define ALLOC_SIZE 10

void setUp(void) {
}

void tearDown(void) {
}

void test_free_string_pair(void) {
	struct string_pair *str_pair = alloc_str_pair(ALLOC_SIZE);
	char *target_result = str_pair->target;
	strcpy(target_result,TEST_DATA);
	free_str_pair(str_pair);
	TEST_ASSERT_TRUE(1);
}
