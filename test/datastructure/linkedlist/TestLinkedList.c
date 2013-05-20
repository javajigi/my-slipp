#include <stdio.h>

#include "datastructure/linkedlist/LinkedList.c"
#include "unity.h"

void setUp(void) {
}

void tearDown(void) {
}

void TEST_NODE_EQULAS(int value, node_t *node) {
	TEST_ASSERT_EQUAL(value, node->value);
	TEST_ASSERT_FALSE(node->next);
}

void test_add_first (void) {
	list_t *list = create();
	TEST_ASSERT_FALSE(list->head);
	add(list, 10);
	node_t *node = list->head;
	TEST_NODE_EQULAS(10, node);
}

void test_add_many(void) {
	list_t *list = create();
	add(list, 10);
	node_t *first = list->head;
	TEST_NODE_EQULAS(10, first);
	add(list, 20);
	node_t *second = first->next;
	TEST_NODE_EQULAS(20, second);
	add(list, 30);
	node_t *third = second->next;
	TEST_NODE_EQULAS(30, third);
}
