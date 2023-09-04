#include <stdio.h>
#include <stdlib.h> 

void main(void)
{
	// 다음과 같이 배열을 채우는 프로그램을 작성한 후, 
	// 맨 오른쪽 열과 맨 아래 행에 각각 행과 열의 합을 저장하는 프로그램을 작성하세요

	int row, col;
	printf("가로 세로 사이즈 : ");
	scanf_s("%d %d", &row, &col);

	//size만큼 배열의 세로 동적할당
	int** Array = (int**)malloc(sizeof(int*) * col);

	//size만큼 배열의 가로 동적할당 
	for (int i = 0; i < col; i++) {
		Array[i] = (int*)malloc(sizeof(int) * row);
	}

	int k = 1;
	int colSum = 0;

	for (int i = 0; i < row - 1; i++) {
		colSum = 0;
		for (int j = 0; j < col - 1; j++) {
			Array[i][j] = k;
			k++;
			colSum += Array[i][j];
			//printf("%d\n", colSum);
		}
		Array[i][col - 1] = colSum;
	}

	int rowSum = 0;
	for (int i = 0; i < col; i++) {
		rowSum = 0;
		for (int j = 0; j < row - 1; j++) {
			rowSum += Array[j][i];
		}
		Array[row - 1][i] = rowSum;
	}



	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%d\t", Array[i][j]);
		}
		printf("\n");
	}

	////메모리 해제
	//for (size_t i = 0; i < row; i++)
	//{
	//	for (size_t j = 0; j < col; j++) {
	//		free(Array[i][j]);
	//	}
	//}
	//free(Array);
}

/*
가로 세로 사이즈 : 4 5
1       2       3       4       10
5       6       7       8       26
9       10      11      12      42
15      18      21      24      78
*/