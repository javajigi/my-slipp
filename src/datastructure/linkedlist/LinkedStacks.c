#include <stdio.h>
#include <stdlib.h>

#define null '\0'

typedef struct element {
	int key;
	struct element *next;
} element_t;

typedef struct stacks {
	element_t *top;
} stacks_t;


stacks_t * create(void) {
	stacks_t * stacks = (stacks_t *)malloc(sizeof(stacks_t));
	stacks->top = null;
	return stacks;
}

void push(stacks_t *stacks, int key) {
	element_t *value = (element_t *)malloc(sizeof(element_t));
	value->key = key;
	value->next = null;

	element_t *top = stacks->top;
	if(top) {
		value->next = stacks->top;
	}

	stacks->top = value;
}

int pop(stacks_t *stacks) {
	element_t *value = stacks->top;
	if (!value) {
		return null;
	}
	stacks->top = value->next;
	int key = value->key;
	free(value);
	return key;
}

int size(stacks_t *stacks) {
	if (!stacks->top) {
		return 0;
	}

	int length = 0;
	element_t *current_element = stacks->top;
	do {
		length++;
		current_element = current_element->next;
	} while(current_element);

	return length;
}
