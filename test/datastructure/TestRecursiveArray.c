#include <stdio.h>

#include "datastructure/RecArray.c"
#include "unity.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_perm(void) {
	char values[] = { 'a', 'b', 'c' };
	perm(values, 0, 3);
}

void test_perm_four(void) {
	char values[] = { 'a', 'b', 'c', 'd' };
	perm(values, 0, 4);
}
