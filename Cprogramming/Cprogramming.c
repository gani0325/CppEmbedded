#include <stdio.h>

void main(void)
{
	// 1~100까지의 합을 구하는 프로그램을 작성하세요
	int sum = 0;

	for (int i = 1; i <= 100; i++) {
		sum += i;
	}

	printf("%d", sum);
}

/*
5050
*/