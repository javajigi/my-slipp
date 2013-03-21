#include <stdio.h>

#include "datastructure/RecArray.c"
#include "unity.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_perm(void) {
	char values[] = { 'a', 'b', 'c' };
	perm(values, 0, 2);
}
