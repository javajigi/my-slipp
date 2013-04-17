#include <stdio.h>

#include "datastructure/stackqueue/Queue.c"
#include "unity.h"

int *queues;
void setUp(void) {
	int max_size = 2;
	queues = initialize(max_size);
}

void tearDown(void) {
	releaseQueue(queues);
}

void test_enqueue_dequeue(void) {
	int value1 = 1;
	enqueue(queues, value1);
	TEST_ASSERT_EQUAL(value1, dequeue(queues));
}

void test_is_empty(void) {
	TEST_ASSERT_TRUE(is_empty());
	int value1 = 1;
	enqueue(queues, value1);
	TEST_ASSERT_FALSE(is_empty());
	TEST_ASSERT_EQUAL(value1, dequeue(queues));
	TEST_ASSERT_TRUE(is_empty());
}

void test_is_full(void) {
	int value1 = 1;
	int value2 = 2;
	enqueue(queues, value1);
	enqueue(queues, value2);
	TEST_ASSERT_TRUE(is_full());
	dequeue(queues);
	TEST_ASSERT_TRUE(is_full());
}

void test_is_empty_dequeue(void) {
	TEST_ASSERT_TRUE(is_empty());
	TEST_ASSERT_EQUAL(-1, dequeue(queues));
}

void test_is_full_enqueue(void) {
	int value1 = 1;
	int value2 = 2;
	enqueue(queues, value1);
	enqueue(queues, value2);
	TEST_ASSERT_TRUE(is_full());
	enqueue(queues, value2);
}
