#include "def.h"

#if TEMPLATE_MATRIX

/*
	���: �� ���� matrix�� �־����� �� matrix�� ���� ����Ѵ�.
	input: matrixA, matrixB, rowIdx, colNum
			rowNum: ���� ����
			colNum: ���� ����
	output: matrixResult
			matrixResult = matrixA + matrixB
*/
void matrixSum(int **matrixResult, int **matrixA, int **matrixB, int rowNum, int colNum)
{
	//
	// ä�� �κ�
	//
	// 
}

/*
	���: �� ���� matrix�� �־����� �� matrix�� ���� ����Ѵ�.
	input: matrixA, matrixB, rowIdx, colNum
			rowNum: ���� ����
			colNum: ���� ����
	output: matrixResult
			matrixResult = matrixA * matrixB
*/
int matrixMulti(int **matrixResult, int **matrixA, int rowNumOfA, int colNumOfA, int **matrixB, int rowNumOfB, int colNumOfB)
{
	int	rowIdx, colIdx, kIdx;

	if(colNumOfA != rowNumOfB) // matrix ������ �� �� ����.
		return -1;

	//
	// ä�� �κ�
	//
	// matrixResult�� �� ����� ���� ���ϱ� ���ؼ� ��Ʈ������ �� ��Ҹ� ��ĵ�Ѵ�.
	// scan�ϸ鼭 �� ����� ���� ����ϱ� ���ؼ� �Ʒ� �۾��� �����Ѵ�.
	//		matrixA�� �� ��� matrixB�� �� ���� ���ؼ� ���ͳ����� ���Ѵ�.
	//		���ͳ����̶� (a1, b1, c1)�� (a2, b2, c3)�� �� ���Ͱ� �ֿ����� �� a1*b1 + a2*b2 + a3*b3�� ���ϴ� ���̴�.

	return 0;
}

/*
	���: �� ���� matrix�� �־����� �־��� matrix�� tranposed matrix�� ���Ѵ�.
	input: matrixA, rowNum, colNum
			rowNum: ���� ����
			colNum: ���� ����
	output: matrixAT
			matrixAT[i][j] = matrixA[j][i]
*/
void matrixTranspose(int **matrixAT, int **matrixA, int rowNum, int colNum)
{

	//
	// ä�� �κ�
	//
	// matrixAT�� �� ����� ���� �����Ѵ�.
	// �̸� ���ؼ� matrixA�� �� ��ҵ��� scan�ϸ鼭 �Ʒ� �۾��� �����Ѵ�.
	//		matrixAT[[i][j] = matrixA[j][i]
	//
}

#endif // TEMPLATE
