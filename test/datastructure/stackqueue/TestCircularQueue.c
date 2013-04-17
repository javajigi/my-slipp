#include <stdio.h>

#include "datastructure/stackqueue/Queue.c"
#include "unity.h"

int *queues;
void setUp(void) {
	int max_size = 3;
	queues = initialize(max_size);
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
	TEST_ASSERT_EQUAL(2, getRear());

//	TEST_ASSERT_EQUAL(value1, dequeue(queues));
//	TEST_ASSERT_EQUAL(1, getFront());
//
//	enqueue(queues, value3);
//	TEST_ASSERT_EQUAL(0, getRear());
//
//	TEST_ASSERT_EQUAL(value2, dequeue(queues));
//	TEST_ASSERT_EQUAL(2, getFront());
//
//	TEST_ASSERT_EQUAL(value3, dequeue(queues));
//	TEST_ASSERT_EQUAL(0, getFront());
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

void test_copy_element(void) {
	queues[1] = 2;
	queues[2] = 3;
	int *new_queues = createQueue(6);
	copy_element(1, 3, 0, queues, new_queues);
	TEST_ASSERT_EQUAL(2, new_queues[0]);
	TEST_ASSERT_EQUAL(3, new_queues[1]);
}

void test_queue_full_normal (void) {
	int *original_queues = initialize(3);
	original_queues[0] = 1;
	original_queues[2] = 3;

	int *target_queues = queue_full(original_queues, 0, 1);
	TEST_ASSERT_EQUAL(5, getFront());
	TEST_ASSERT_EQUAL(1, getRear());
	TEST_ASSERT_EQUAL(3, target_queues[0]);
	TEST_ASSERT_EQUAL(1, target_queues[1]);
}

void test_queue_front_zero (void) {
	int *original_queues = initialize(3);
	original_queues[1] = 2;
	original_queues[2] = 3;

	int *target_queues = queue_full(original_queues, 2, 0);
	TEST_ASSERT_EQUAL(5, getFront());
	TEST_ASSERT_EQUAL(1, getRear());
	TEST_ASSERT_EQUAL(2, target_queues[0]);
	TEST_ASSERT_EQUAL(3, target_queues[1]);
}

void test_queue_front_max (void) {
	int *original_queues = initialize(3);
	original_queues[0] = 1;
	original_queues[1] = 2;

	int *target_queues = queue_full(original_queues, 1, 2);
	TEST_ASSERT_EQUAL(5, getFront());
	TEST_ASSERT_EQUAL(1, getRear());
	TEST_ASSERT_EQUAL(1, target_queues[0]);
	TEST_ASSERT_EQUAL(2, target_queues[1]);
}
