#include <stdio.h>

void main(void)
{
	int x = 0, y = 0;
	for (y = 0; y < 5; y++)
	{
		for (x = 0; x < y + 1; ++x) // x는 0부터 초기화되며 y에 1을 더한 값보다 작을때 실행
		{
			printf("*\t");
		}

		putchar('\n');
	}
}

/*
*
*       *
*       *       *
*       *       *       *
*       *       *       *       *
*/