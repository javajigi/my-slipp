#include <stdio.h>

#include "datastructure/TowerOfHanoi.c"
#include "unity.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_hanoi_two_length(void) {
	int firstTower[] = { 2, 1 }, secondTower[] = { -1, -1 }, thirdTower[] = { -1, -1 };
	int length = 2;
	int firstLength = 2, secondLength = 0, thirdLength = 0;
	struct tower *first_tower = new_tower(firstTower, length, firstLength);
	struct tower *second_tower = new_tower(secondTower, length, secondLength);
	struct tower *third_tower = new_tower(thirdTower, length, thirdLength);

	hanoi(first_tower, second_tower, third_tower, length);
	TEST_ASSERT_EQUAL(1, thirdTower[1]);
	TEST_ASSERT_EQUAL(2, thirdTower[0]);
}

void test_hanoi_three_length(void) {
	int firstTower[] = { 3, 2, 1 }, secondTower[] = { -1, -1, -1 }, thirdTower[] = { -1, -1, -1 };
	int length = 3;
	int firstLength = 3, secondLength = 0, thirdLength = 0;
	struct tower *first_tower = new_tower(firstTower, length, firstLength);
	struct tower *second_tower = new_tower(secondTower, length, secondLength);
	struct tower *third_tower = new_tower(thirdTower, length, thirdLength);

	hanoi(first_tower, second_tower, third_tower, length);
	TEST_ASSERT_EQUAL(1, thirdTower[2]);
	TEST_ASSERT_EQUAL(2, thirdTower[1]);
	TEST_ASSERT_EQUAL(3, thirdTower[0]);
}

void test_hanoi_four_length(void) {
	int firstTower[] = { 4, 3, 2, 1 }, secondTower[] = { -1, -1, -1, -1 },
			thirdTower[] = { -1, -1, -1, -1 };
	int length = 4;
	int firstLength = 4, secondLength = 0, thirdLength = 0;
	struct tower *first_tower = new_tower(firstTower, length, firstLength);
	struct tower *second_tower = new_tower(secondTower, length, secondLength);
	struct tower *third_tower = new_tower(thirdTower, length, thirdLength);

	hanoi(first_tower, second_tower, third_tower, length);
	for (int i = 0; i < length; i++) {
		printf("first tower : %d\n", first_tower->values[i]);
	}
	printf("first tower length : %d\n", first_tower->length);
	for (int i = 0; i < length; i++) {
		printf("second tower : %d\n", second_tower->values[i]);
	}
	printf("second tower length : %d\n", second_tower->length);
	for (int i = 0; i < length; i++) {
		printf("third tower : %d\n", third_tower->values[i]);
	}
	printf("third tower length : %d\n", third_tower->length);
	TEST_ASSERT_EQUAL(1, thirdTower[3]);
	TEST_ASSERT_EQUAL(2, thirdTower[2]);
	TEST_ASSERT_EQUAL(3, thirdTower[1]);
	TEST_ASSERT_EQUAL(4, thirdTower[0]);
}

void test_hanoi_sixtyfour_length(void) {
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
	for (int i = 0; i < MAX_VALUE; i++) {
		printf("first tower : %d\n", first_tower->values[i]);
	}
	printf("first tower length : %d\n", first_tower->length);
	for (int i = 0; i < MAX_VALUE; i++) {
		printf("second tower : %d\n", second_tower->values[i]);
	}
	printf("second tower length : %d\n", second_tower->length);
	for (int i = 0; i < MAX_VALUE; i++) {
		printf("third tower : %d\n", third_tower->values[i]);
	}
	printf("third tower length : %d\n", third_tower->length);


	for (int var = 0; var < MAX_VALUE; var++) {
		TEST_ASSERT_EQUAL(MAX_VALUE, thirdTower[var]);
		MAX_VALUE--;
	}
}
