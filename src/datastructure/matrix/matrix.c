#include "def.h"

#if !TEMPLATE_MATRIX

void matrixSum(int **matrixResult, int **matrixA, int **matrixB, int rowNum, int colNum)
{
	int	rowIdx, colIdx;

	for(rowIdx=0; rowIdx < rowNum; rowIdx++)
		for(colIdx=0; colIdx < colNum; colIdx++)
			matrixResult[rowIdx][colIdx] = matrixA[rowIdx][colIdx] + matrixB[rowIdx][colIdx];
}

int matrixMulti(int **matrixResult, int **matrixA, int rowNumOfA, int colNumOfA, int **matrixB, int rowNumOfB, int colNumOfB)
{
	int	rowIdx, colIdx, kIdx;

	if(colNumOfA != rowNumOfB)
		return -1;

	for(rowIdx=0; rowIdx < rowNumOfA; rowIdx++) {
		for(colIdx=0; colIdx < colNumOfB; colIdx++) {
			matrixResult[rowIdx][colIdx] = 0;
			for(kIdx=0; kIdx < colNumOfA; kIdx++)
				matrixResult[rowIdx][colIdx] += matrixA[rowIdx][kIdx] * matrixB[kIdx][colIdx];
		}
	}

	return 0;
}

void matrixTranspose(int **matrixAT, int **matrixA, int rowNum, int colNum)
{
	int	rowIdx, colIdx;

	for(rowIdx=0; rowIdx < rowNum; rowIdx++)
		for(colIdx=0; colIdx < colNum; colIdx++)
			matrixAT[colIdx][rowIdx] = matrixA[rowIdx][colIdx];

	return;	
}


#endif // !TEMPLATE
