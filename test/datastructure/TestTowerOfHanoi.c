#include <stdio.h>

#include "datastructure/TowerOfHanoi.c"
#include "unity.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_hanoi(void) {
	int MAX_VALUE = 10;
	int firstTower[MAX_VALUE], secondTower[MAX_VALUE], thirdTower[MAX_VALUE];
	for (int var = 0; var < MAX_VALUE; var++) {
		firstTower[var] = MAX_VALUE - var;
		secondTower[var] = -1;
		thirdTower[var] = -1;
	}
	int firstLength = MAX_VALUE, secondLength = 0, thirdLength = 0;
	struct tower *first_tower = new_tower(firstTower, MAX_VALUE, firstLength);
	struct tower *second_tower = new_tower(secondTower, MAX_VALUE, secondLength);
	struct tower *third_tower = new_tower(thirdTower, MAX_VALUE, thirdLength);

	hanoi(first_tower, second_tower, third_tower, MAX_VALUE);

	for (int var = 0; var < MAX_VALUE; var++) {
		TEST_ASSERT_EQUAL(MAX_VALUE, thirdTower[var]);
		MAX_VALUE--;
	}
}
