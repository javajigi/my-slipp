#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int max_size, rear, front;

int * createQueue(int _max_size) {
	max_size = _max_size;
	rear = -1;
	front = -1;
	return (int *) malloc(max_size * sizeof(int));
}

void releaseQueue(int *queues) {
	free(queues);
}

int is_empty() {
	return rear == front;
}

int is_full() {
	return rear == max_size - 1;
}

void enqueue(int *queues, int element) {
	if (is_full()) {
		return;
	}
	queues[++rear] = element;
}

int dequeue(int *queues) {
	if (is_empty()) {
		return -1;
	}
	return queues[++front];
}
