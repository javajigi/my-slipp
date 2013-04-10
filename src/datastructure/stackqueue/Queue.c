#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int max_size, rear, front;

int * createQueue(int _max_size) {
	max_size = _max_size;
	rear = 0;
	front = 0;
	return (int *) malloc(max_size * sizeof(int));
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

void enqueue(int *queues, int element) {
	if (is_full()) {
		return;
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
