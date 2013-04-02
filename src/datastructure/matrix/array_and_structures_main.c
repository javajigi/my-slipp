/*
   �ۼ���: �赿��
   �ۼ���: 2013.03.30
   ����: array�� structure ��� ����
   �� ����
       1. 2D array ��뿹��
	   2. structure ��� ����
	   3. typedef ��� ����
	   4. matrices ��� ����
*/

#include <stdio.h>

extern void testMake2DArray(void);
extern void	test2DArrayOfFixedSize(void);
extern void	testMatrixSum(void);
extern void	testMatrixMulti(void);
extern void	testMatrixTranspose(void);
extern void	testStructures(void);
extern void	testSelfReferentialStrucutures(void);
extern void	testRectangleStructures(void);

int main(void)
{
	testMake2DArray();

	test2DArrayOfFixedSize();

	testMatrixSum();

	testMatrixMulti();

	testMatrixTranspose();

	testStructures();

	testSelfReferentialStrucutures();

	testRectangleStructures();

	return 0;
}