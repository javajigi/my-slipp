#include <stdio.h>

#include "datastructure/TowerOfHanoi2.c"
#include "unity.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_hanoi_two_length(void) {
	int length = 2;
	int firstTower[] = { 2, 1 };
	int secondTower[length];
	int thirdTower[length];
	hanoi(firstTower, secondTower, thirdTower, length);
	TEST_ASSERT_EQUAL(1, thirdTower[1]);
	TEST_ASSERT_EQUAL(2, thirdTower[0]);
}

void test_hanoi_three_length (void) {
	int length = 3;
	int firstTower[] = {3,2,1};
	int secondTower[length];
	int thirdTower[length];
	hanoi(firstTower, secondTower, thirdTower, length);
	TEST_ASSERT_EQUAL(1, thirdTower[2]);
	TEST_ASSERT_EQUAL(2, thirdTower[1]);
	TEST_ASSERT_EQUAL(3, thirdTower[0]);
}

void test_hanoi_four_length (void) {
	int length = 4;
	int firstTower[] = {4,3,2,1};
	int secondTower[length];
	int thirdTower[length];
	hanoi(firstTower, secondTower, thirdTower, length);
	TEST_ASSERT_EQUAL(1, thirdTower[3]);
	TEST_ASSERT_EQUAL(2, thirdTower[2]);
	TEST_ASSERT_EQUAL(3, thirdTower[1]);
	TEST_ASSERT_EQUAL(4, thirdTower[0]);
}
