#include <stdlib.h>

struct tower {
	int *values;
	int length;
};

struct tower * alloc_tower(int length) {
	struct tower *newTower = (struct tower *) malloc(sizeof(struct tower));
	newTower->values = (int *) malloc(sizeof(int) * length);
	return newTower;
}

struct tower * new_tower(int *values, int new_array_length, int length) {
	struct tower *newTower = alloc_tower(new_array_length);
	newTower->values = values;
	newTower->length = length;
	return newTower;
}

void swap(struct tower *source, struct tower *target) {
	int temp = target->values[target->length];
	target->values[target->length] = source->values[source->length -1];
	source->values[source->length - 1] = temp;
	source->length--;
	target->length++;
}

void hanoi(struct tower *first_tower, struct tower *second_tower, struct tower *third_tower, int length) {
	if (length == 1) {
		swap(first_tower, third_tower);
		return;
	}
	hanoi(first_tower, third_tower, second_tower, length -1);
	swap(first_tower, third_tower);
	hanoi(second_tower, first_tower, third_tower, length -1);
}
