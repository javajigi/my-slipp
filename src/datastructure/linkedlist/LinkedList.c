#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node* next;
} node_t;

typedef struct list {
	node_t* head;
} list_t ;

list_t* create(void) {
	list_t *list = (list_t *)malloc(sizeof(list_t));
	list->head = 0;
	return list;
}

void add(list_t *list, int value) {
	node_t *node = (node_t *)malloc(sizeof(node_t));
	node->value = value;
	node->next = 0;

//	while(1) {
//		node_t *first = list->head;
//		if(!first) {
//			list->head = node;
//			return;
//		} else {
//			first = first->next;
//		}
//	}

	node_t *first = list->head;
	if(!first) {
		list->head = node;
		return;
	}

	printf("node size is over 1\n");
	node_t *second = first->next;
	if (!second) {
		first->next = node;
		return;
	}

	printf("node size is over 2\n");
	node_t *third = second->next;
	if (!third) {
		second->next = node;
		return;
	}
}
