#include <stdio.h>

#include "datastructure/stackqueue/Stack.c"
#include "unity.h"

int *stacks;
void setUp(void) {
	int max_size = 2;
	stacks = createStack(max_size);
}

void tearDown(void) {
	releaseStack(stacks);
}

void test_push_pop(void) {
	int value1 = 1;
	int value2 = 2;
	push(stacks, value1);
	push(stacks, value2);
	TEST_ASSERT_EQUAL(value2, pop(stacks));

}

void test_is_empty(void) {
	TEST_ASSERT_TRUE(isEmpty(stacks));
	pop(stacks);
}

void test_is_full(void) {
	TEST_ASSERT_FALSE(isFull(stacks));
	push(stacks, 1);
	push(stacks, 2);
	TEST_ASSERT_TRUE(isFull(stacks));
	push(stacks, 3);
}
