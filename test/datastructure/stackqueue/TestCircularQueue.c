#include <stdio.h>

#include "datastructure/stackqueue/Queue.c"
#include "unity.h"

int *queues;
void setUp(void) {
	int max_size = 3;
	queues = createQueue(max_size);
}

void tearDown(void) {
	releaseQueue(queues);
}

void test_enqueue_dequeue(void) {
	int value1 = 1;
	int value2 = 2;
	int value3 = 3;
	enqueue(queues, value1);
	TEST_ASSERT_EQUAL(1, getRear());
	enqueue(queues, value2);
	TEST_ASSERT_EQUAL(2, getRear());
	TEST_ASSERT_TRUE(is_full());
	enqueue(queues, value3);
	TEST_ASSERT_TRUE(is_full());

	enqueue(queues, value2);
	TEST_ASSERT_EQUAL(2, getRear());

	TEST_ASSERT_EQUAL(value1, dequeue(queues));
	TEST_ASSERT_EQUAL(1, getFront());

	enqueue(queues, value3);
	TEST_ASSERT_EQUAL(0, getRear());

	TEST_ASSERT_EQUAL(value2, dequeue(queues));
	TEST_ASSERT_EQUAL(2, getFront());

	TEST_ASSERT_EQUAL(value3, dequeue(queues));
	TEST_ASSERT_EQUAL(0, getFront());
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
	int value3 = 3;
	enqueue(queues, value1);
	enqueue(queues, value2);
	TEST_ASSERT_TRUE(is_full());
	dequeue(queues);
	enqueue(queues, value3);
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

