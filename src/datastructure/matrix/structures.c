#include "def.h"

#if !TEMPLATE_STRUCTURES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct rectangle {
	int x, y;
	int width, height;
};

typedef struct {
	char	name[10];
	int		age;
	float	salary;
} humanBeing_t;

typedef struct list {
	char data;
	struct list *next;
} list_t;

int humansEqualByCallByValue(humanBeing_t person1, humanBeing_t person2)
{
	if(person1.age != person2.age)
		return 0;

	if(person1.salary != person2.salary)
		return 0;

	if(strcmp(person1.name, person2.name))
		return 0;

	return 1;
}

int humansEqualByCallByReference(humanBeing_t *person1, humanBeing_t *person2)
{
	if(person1->age != person2->age)
		return 0;

	if(person1->salary != person2->salary)
		return 0;

	if(strcmp(person1->name, person2->name))
		return 0;

	return 1;
}


void testStructures(void)
{
	humanBeing_t	person1, person2;

	strcpy(person1.name, "kim");
	person1.age = 30;
	person1.salary = 200;

	strcpy(person2.name, "kim");
	person2.age = 30;
	person2.salary = 200;

	if(humansEqualByCallByValue(person1, person2)) {
		printf("�� ����� �̸�, ����, �޿��� ����\n");
	}
	else
		printf("�λ���� ����, �޿�, �̸� �� �ϳ��� �ٸ�\n");

	if(humansEqualByCallByReference(&person1, &person2)) {
		printf("�� ����� �̸�, ����, �޿��� ����\n");
	}
	else
		printf("�λ���� ����, �޿�, �̸� �� �ϳ��� �ٸ�\n");

}

void	testSelfReferentialStrucutures(void)
{
	list_t	item1, item2, item3;
	list_t	*tmpItem;

	item1.data = 'a';
	item2.data = 'b';
	item3.data = 'c';

	item1.next = &item2;
	item2.next = &item3;
	item3.next = NULL; 

	tmpItem = &item1;

	while(tmpItem) {
		printf("item: %c\n", tmpItem->data);
		tmpItem = tmpItem->next;
	}
}

void testRectangleStructures(void)
{
	struct rectangle rec1;

	rec1.x = 0;
	rec1.y = 0;

	rec1.width = 10;
	rec1.height= 20;

	printf("rec pos (%d, %d) with height %d and width %d\n", rec1.x, rec1.y, rec1.width, rec1.height);
}


#endif // !TEMPLATE_STRUCTURES
