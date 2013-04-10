#include <stdio.h>
#include <stdlib.h>

extern int **make2DArray(int rowNum, int colNum);

void print2DArray(int **twoDimArray, int rowNum, int colNum)
{
	int	rowIdx, colIdx;

	for(rowIdx = 0; rowIdx < rowNum; rowIdx++) {
		for(colIdx = 0; colIdx < colNum; colIdx++)
			printf("%10d ", twoDimArray[rowIdx][colIdx]);
		printf("\n");
	}

	return;
}

void print2DArrayOfFixedSize(int twoDimArray[][5], int rowNum, int colNum)
{
	int	rowIdx, colIdx;

	for(rowIdx = 0; rowIdx < rowNum; rowIdx++) {
		for(colIdx = 0; colIdx < colNum; colIdx++)
			printf("%10d ", twoDimArray[rowIdx][colIdx]);
		printf("\n");
	}

	return;
}

void testMake2DArray(void)
{
	int	**twoDimArray;
	int	rowNum, colNum;
	int	rowIdx, colIdx;

	printf("start testMake2DArray()\n");

	rowNum = 5;
	colNum = 5;

	twoDimArray = make2DArray(rowNum, colNum);

	for(rowIdx = 0; rowIdx < rowNum; rowIdx++)
		for(colIdx = 0; colIdx < colNum; colIdx++) 
			twoDimArray[rowIdx][colIdx] = rand() % 10;
	
	print2DArray(twoDimArray, rowNum, colNum);

	return;
}

void test2DArrayOfFixedSize(void)
{
	int	test2DArray[3][5] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int	rowIdx, colIdx;

	printf("start test2DArrayOfFixedSize()\n");

	for(rowIdx = 0; rowIdx < 3; rowIdx++)
		for(colIdx = 0; colIdx < 5; colIdx++) 
			test2DArray[rowIdx][colIdx] = rand() % 10;

	print2DArrayOfFixedSize(test2DArray, 3, 5);

	return;
}
