#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int max_size, rear, front;

int *createQueue(int _max_size) {
	return (int *) malloc(max_size * sizeof(int));
}

int *initialize(int _max_size) {
	max_size = _max_size;
	rear = 0;
	front = 0;
	return createQueue(max_size);
}

int getRear(void) {
	return rear;
}

int getFront(void) {
	return front;
}

void releaseQueue(int *queues) {
	free(queues);
}

int is_empty() {
	printf(" isEmpty : rear : %d, front : %d\n", rear, front);
	return rear == front;
}

int is_full() {
	return (rear + 1) % max_size == front;
}

void copy_element(int original_start, int original_end, int target_start, int *queues, int *new_queues) {
	printf("os : %d, oe : %d, ts : %d\n", original_start, original_end, target_start);
	for (int i = 0; i < original_end - original_start; i++) {
		new_queues[target_start + i] = queues[original_start + i];
	}
}

int *queue_full(int *queues, int _rear, int _front) {
	int *new_queues = createQueue(max_size * 2);
	copy_element(_front+1, max_size, 0, queues, new_queues);
	copy_element(0, _rear + 1, max_size - (_front + 1), queues, new_queues);
	front = 2 * max_size - 1;
	rear = max_size - 2;
	max_size = max_size * 2;
	return new_queues;
}

void enqueue(int *queues, int element) {
	if (is_full()) {
		queues = queue_full(queues, rear, front);
	}
	queues[++rear] = element;
	rear = rear % max_size;
}

int dequeue(int *queues) {
	if (is_empty()) {
		return -1;
	}
	printf(" dequeue : rear : %d, front : %d\n", rear, front);
	int element = queues[++front];
	front = front % max_size;
	return element;
}
