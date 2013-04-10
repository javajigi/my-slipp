#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int max_size, top;

int * createStack(int _max_size) {
	max_size = _max_size;
	top = -1;
	return (int *)malloc(max_size * sizeof(int));
}

int isEmpty(int *stacks) {
	if (top < 0) {
		return TRUE;
	}
	return FALSE;
}

int isFull(int *stacks) {
	if (top == max_size -1) {
		return TRUE;
	}
	return FALSE;
}

void push(int *stacks, int element) {
	if (isFull(stacks)) {
		printf("this stack is full. you can't pull!\n");
		return;
	}

	stacks[++top] = element;
}

int pop(int *stacks) {
	if (isEmpty(stacks)) {
		printf("this stack is empty. you can't pop!\n");
		return -1;
	}

	return stacks[top--];
}

void releaseStack(int *stacks) {
	free(stacks);
}
