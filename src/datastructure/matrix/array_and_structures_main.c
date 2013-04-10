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
