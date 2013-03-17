#include <stdio.h>
#include <stdlib.h>

void pointer() {
	int num1;
	int *ptr_l1;
	int **ptr_l2;	
	printf("=================declared, but not initialize=================\n");
	printf(" ptrl2      ptrl1       num1\n");
	printf(" [   ]      [   ]       [  ]\n\n");
		
	printf("addr of num1= %p, val= %08X \n", &num1, num1);
	printf("addr of ptr_l1= %p, val= %p \n", &ptr_l1, ptr_l1);
	printf("addr of ptr_l2= %p, val= %p \n", &ptr_l2, ptr_l2);

	ptr_l2 = &ptr_l1;
	ptr_l1 = &num1;
	num1 = 0xBADBAB0;
	printf("\n=================after initializing=================\n");	
	printf(" ptrl2      ptrl1       num1\n");
	printf(" [ +-]----->[ +-]----->[0XBA..]\n\n");
	printf("addr of num1= %p, val= %08X\n", &num1, num1);	
	printf("addr of ptr_l1= %p, val= %p, *val= %08X\n", &ptr_l1, ptr_l1, *ptr_l1);
	printf("addr of ptr_l2= %p, val= %p, *val = %p, **val=%08X\n" , &ptr_l2, ptr_l2, *ptr_l2, **ptr_l2);
}
