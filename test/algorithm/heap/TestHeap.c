#include <stdio.h>

#include "algorithm/heap/Heap.c"
#include "unity.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_allocMaxHeapWithCapacity_free(void) {
	heap_t * heap = allocMaxHeapWithCapacity(5);
	freeMaxHeap(heap);
}

void test_printHeap(void) {
	heap_t * heap = allocMaxHeapWithCapacity(5);
	printHeap(heap);
}

void test_makeSampleHeap(void) {
	heap_t * heap = makeSampleHeap(10);
	printHeap(heap);
}

void test_isMaxHeap(void) {
	heap_t * heap = makeSampleHeap(5);
	int actual = isMaxHeap(heap);
	TEST_ASSERT_EQUAL(1, actual);
}

void test_isNotMaxHeap(void) {
	heap_t * heap = makeSampleHeap(3);
	heap->element[1] = 1;
	int actual = isMaxHeap(heap);
	TEST_ASSERT_EQUAL(0, actual);

	heap = makeSampleHeap(5);
	heap->element[5] = 10;
	actual = isMaxHeap(heap);
	TEST_ASSERT_EQUAL(0, actual);

	heap = makeSampleHeap(7);
	heap->element[7] = 10;
	actual = isMaxHeap(heap);
	TEST_ASSERT_EQUAL(0, actual);
}

void test_heapify(void) {
	heap_t * heap = makeSampleHeap(3);
	int position = 1;
	heap->element[position] = 1;
	int actual = isMaxHeap(heap);
	TEST_ASSERT_EQUAL(0, actual);
	printHeap(heap);
	heapify(heap, position);
	actual = isMaxHeap(heap);
	printHeap(heap);
	TEST_ASSERT_EQUAL(1, actual);
}

void test_heapify_leftside(void) {
	heap_t * heap = makeSampleHeap(7);
	int position = 1;
	heap->element[position] = 1;
	int actual = isMaxHeap(heap);
	TEST_ASSERT_EQUAL(0, actual);
	printHeap(heap);
	heapify(heap, position);
	actual = isMaxHeap(heap);
	printHeap(heap);
	TEST_ASSERT_EQUAL(1, actual);
}

void test_heapify_rightside(void) {
	heap_t * heap = makeSampleHeap(7);
	int position = 1;
	heap->element[1] = 1;
	heap->element[3] = 7;
	int actual = isMaxHeap(heap);
	TEST_ASSERT_EQUAL(0, actual);
	printHeap(heap);
	heapify(heap, position);
	actual = isMaxHeap(heap);
	printHeap(heap);
	TEST_ASSERT_EQUAL(1, actual);
}
