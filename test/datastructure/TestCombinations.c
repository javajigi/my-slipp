#include <stdio.h>

#include "datastructure/Combinations.c"
#include "unity.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_combination(void) {
	int currentPosition = 0;
	char values[] = { 'a', 'b', 'c' };
	combinations(values, &currentPosition, 0, 2);
}
