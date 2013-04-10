#include "def.h"

#if TEMPLATE_STRUCTURES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct humanBeing {
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
	//
	// ä�� �κ�
	//
	// �� ����� age, �޿�, �̸��� ��� ������ 1�� return
	// �ϳ��� �ٸ��� 0�� return
	//

	return 1;
}

//
// call by reference�� �� ����� ������ �Է¹޾Ƽ� �� ����� �ƴ�, �޿�, �̸��� ������ �˻��ϴ� �Լ�
//
int humansEqualByCallByReference(humanBeing_t *person1, humanBeing_t *person2)
{
	//
	// ä�� �κ�
	//
	// �� ����� age, �޿�, �̸��� ��� ������ 1�� return
	// �ϳ��� �ٸ��� 0�� return
	//

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


#endif // TEMPLATE_STRUCTURES
