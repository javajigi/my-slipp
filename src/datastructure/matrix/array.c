#include <stdlib.h>
#include "def.h"

#if !TEMPLATE_ARRAY

int **make2DArray(int rowNum, int colNum)
{
	int **intArr;
	int	rowIdx;

	intArr = (int **)malloc(sizeof(int *)*rowNum);

	if(!intArr)
		return (int **)intArr;

	for(rowIdx = 0; rowIdx < rowNum; rowIdx++) {
		intArr[rowIdx] = (int *)malloc(sizeof(int)*colNum);

		/*
		if(intArr[rowIdx] == (int *)NULL) {
			int	tmpIdx;
			for(tmpIdx = 0; tmpIdx < rowIdx - 1; tmpIdx++) {
				free(intArr[rowIdx]);
			}

			free(intArr);
			
			return (int **)NULL;
		}
		*/
	}

	return intArr;
}

#endif // !TEMPLATE
