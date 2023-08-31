#include <stdio.h>
#include <stdlib.h> 

void main(void)
{
	int input;
	printf("배열의 사이즈 : ");
	scanf_s("%d", &input);

	//size만큼 배열의 세로 동적할당
	int** Array = (int**)malloc(sizeof(int*) * input);

	//size만큼 배열의 가로 동적할당 
	for (int i = 0; i < input; i++) {
		Array[i] = (int*)malloc(sizeof(int) * input);
	}

	//int k = 1;
	//for (int i = 0; i < input; i++) {
	//	for (int j = 0; j < input; j++) {
	//		Array[i][j] = k;
	//		k++;
	//	}
	//}

	int k = 1;
	int center = input / 2;

	for (int i = 0; i < center; i++) {
		for (int j = input - i - 1; j >= i; j--) {
			Array[i][j] = k;
			k++;
		}
		for (int j = i + 1; j < input - i; j++) {
			Array[j][i] = k;
			k++;
		}
		for (int j = i + 1; j < input - i; j++) {
			Array[input - 1 - i][j] = k;
			k++;
		}
		for (int j = input - 2 - i; j >= 1 + i; j--) {
			Array[j][input - 1 - i] = k;
			k++;
		}
	}

	Array[center][center] = input * input;

	for (int i = 0; i < input; i++) {
		for (int j = 0; j < input; j++) {
			printf("%d\t", Array[i][j]);
		}
		printf("\n");
	}

	//메모리 해제
	for (size_t i = 0; i < input; i++)
	{
		free(Array[i]);
	}
	free(Array);
}

/*
배열의 사이즈 : 7
7       6       5       4       3       2       1
8       29      28      27      26      25      24
9       30      43      42      41      40      23
10      31      44      49      48      39      22
11      32      45      46      47      38      21
12      33      34      35      36      37      20
13      14      15      16      17      18      19
*/