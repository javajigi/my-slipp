#include <stdio.h>

#include "datastructure/Polynomial.c"
#include "unity.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_padd(void) {
	int startd = 0;
	int finishd = 0;
	padd(0, 1, 2, 5, &startd, &finishd);
	TEST_ASSERT_EQUAL(6, startd);
	TEST_ASSERT_EQUAL(10, finishd);
}
