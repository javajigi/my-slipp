#include <stdio.h>
#include <stdlib.h>

typedef struct heap {
	int size;
	int capacity;
	int *element;
} heap_t;

heap_t* allocMaxHeapWithCapacity(int capacity) {
	heap_t *heap = (heap_t *) malloc(sizeof(heap_t));
	heap->element = (int *) malloc(capacity + 1);
	heap->capacity = 64;
	return heap;
}

heap_t* makeSampleHeap(int size) {
	heap_t *heap = allocMaxHeapWithCapacity(64);
	for (int i = 1; i <= size; i++) {
		heap->element[i] = size - i + 1;
		heap->size++;
	}
	return heap;
}

int isMaxHeapDescendant(heap_t* heap, int index) {
	printf("size : %d, index : %d\n", heap->size, index);
	if (heap->size <= index) {
		return 1;
	}

	int root = heap->element[index];
	int left = heap->element[2 * index];
	int right = heap->element[2 * index + 1];

	if (root < left) {
		return 0;
	}

	if (root < right) {
		return 0;
	}

	int leftResult = isMaxHeapDescendant(heap, 2 * index);
	if (leftResult == 0) {
		return 0;
	}

	int rightResult = isMaxHeapDescendant(heap, 2 * index + 1);
	if (rightResult == 0) {
		return 0;
	}

	return 1;
}

int isMaxHeap(heap_t* heap) {
	int index = 1;
	return isMaxHeapDescendant(heap, index);
}

void swap(heap_t* heap, int source, int target) {
	int temp = heap->element[source];
	heap->element[source] = heap->element[target];
	heap->element[target] = temp;
}

void heapify(heap_t* heap, int position) {
	if (heap->size <= position) {
		return;
	}

	int root = heap->element[position];
	int left = heap->element[2 * position];
	int right = heap->element[2 * position + 1];

	int largest = position;
	if (root < left) {
		largest = 2 * position;
	}

	if (root < right && left < right) {
		largest = 2 * position + 1;
	}

	swap(heap, position, largest);

	heapify(heap, 2 * position);
	heapify(heap, 2 * position + 1);
}

void freeMaxHeap(heap_t* heap) {
	free(heap->element);
	free(heap);
}

void printHeap(heap_t* heap) {
	for (int i = 0; i < heap->size; i++) {
		printf("value : %d \n", heap->element[i + 1]);
	}
}
