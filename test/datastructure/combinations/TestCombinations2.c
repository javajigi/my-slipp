#include <stdio.h>

#include "datastructure/combinations/Combinations2.c"
#include "unity.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_combinations (void) {
	char values[] = { 'a', 'b', 'c' };
	int bin[3];
	combinations(values, bin, 3);
}

void test_from_int_to_binary(void) {
	int bin[3] = { -1, -1, -1 };

}
