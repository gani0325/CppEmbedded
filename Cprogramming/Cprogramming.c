#include <stdio.h>

void main(void)
{
	// 사용자로부터 다섯 개의 정수를 입력받고, 
	// 그 중 가장 큰 수와 가장 작은 수를 골라서 출력하는 프로그램을 작성하세요

	int max = -1e9, min = 1e9;
	int nInput = 0;

	for (int i = 0; i < 5; ++i)
	{
		scanf_s("%d", &nInput);
		if (nInput > max) {
			max = nInput;
		}
		else if (nInput < min) {
			min = nInput;
		}
	}

	printf("가장 큰 수 : %d, 가장 작은 수 : %d", max, min);
}

/*
4
5
7
1
6
가장 큰 수 : 7, 가장 작은 수 : 1
*/