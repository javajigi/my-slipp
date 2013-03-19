#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct string_pair {
	char *target;
	const char *source;
};

struct string_pair * alloc_str_pair(int target_size) {
	struct string_pair *str_pair;
	str_pair = malloc(sizeof(str_pair));
	str_pair->target = malloc(target_size);
	return str_pair;
}


void free_str_pair(struct string_pair *str_pair) {
	free(str_pair->target);
	free(str_pair);
}

int length_str_pair_source(const char *value) {
	int i = 0;
	while (1) {
		if (value[i] == '\0') {
			return i;
		}
		i++;
	}
	return 0;
}

void copy_str_pair(struct string_pair *str_pair) {
	int length = length_str_pair_source(str_pair->source);
	for (int i = 0; i < length; i++) {
		str_pair->target[i] = str_pair->source[i];
	}
	printf("copy string of %s is %s\n", str_pair->source, str_pair->target);
}

void copy_str_pair_reverse(struct string_pair *str_pair) {
	int length = length_str_pair_source(str_pair->source);
	for (int i = 0; i < length; i++) {
		str_pair->target[length-(i+1)] = str_pair->source[i];
	}
	printf("reverse string of %s is %s\n", str_pair->source, str_pair->target);
}
