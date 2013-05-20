#include <stdio.h>

#include "unity.h"
#include "datastructure/linkedlist/LinkedStacks.c"

void setUp(void) {
}

void tearDown(void) {
}

void test_create (void) {
	stacks_t * stacks = create();
	TEST_ASSERT_FALSE(stacks->top);
}

void test_push (void) {
	stacks_t * stacks = create();
	push(stacks, 1);
	element_t * top = stacks->top;
	TEST_ASSERT_EQUAL(1, top->key);
	TEST_ASSERT_FALSE(top->next);


	push(stacks, 2);
	top = stacks->top;
	TEST_ASSERT_EQUAL(2, top->key);
	TEST_ASSERT_TRUE(top->next);
}

void test_pop (void) {
	stacks_t * stacks = create();
	int value = pop(stacks);
	TEST_ASSERT_FALSE(value);

	push(stacks, 1);
	push(stacks, 2);

	value = pop(stacks);
	TEST_ASSERT_EQUAL(2, value);
	value = pop(stacks);
	TEST_ASSERT_EQUAL(1, value);
}

void test_size (void) {
	stacks_t * stacks = create();
	TEST_ASSERT_EQUAL(0, size(stacks));
	push(stacks, 1);
	TEST_ASSERT_EQUAL(1, size(stacks));
}
