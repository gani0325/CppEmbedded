#include <stdio.h>
#include <stdlib.h> 

void main(void)
{
	int input=7;
	printf("배열의 사이즈 : ");
	//scanf_s("%d", &input);

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
		for (int j = i; j < input - i;j++) {
			Array[i][j] = k;
			k++;
		}
		for (int j = i + 1; j < input - i; j++) {
			Array[j][input - 1 - i] = k;
			k++;
		}
		for (int j = input - 2 - i; j >= i; j--) {
			Array[input - 1 - i][j] = k;
			k++;
		}
		for (int j = 1 + i; j <= input - 2 - i; j++) {
			Array[input - 1 - j][i] = k;
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

*/