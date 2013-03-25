#include <stdio.h>

#include "datastructure/Combinations.c"
#include "unity.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_combinations_two_length(void) {
	char values[] = { 'a', 'b', 'c' };
	combinations_two(values, 3, 2);
}

void test_combination_three_length(void) {
	char values[] = { 'a', 'b', 'c', 'd', 'e' };
	combinations_three(values, 5, 3);
}

void test_combination_four_length(void) {
	char values[] = { 'a', 'b', 'c', 'd', 'e' };
	combinations_four(values, 5, 4);
}
