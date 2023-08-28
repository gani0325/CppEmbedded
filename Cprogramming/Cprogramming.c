#include <stdio.h>

void main(void)
{
	int x = 0, y = 0;
	for (y = 0; y < 5; y++)
	{
		for (x = 0; x < 4; ++x)
		{
			if (x > 2)
				break; // x값이 3이 되었을 때 break문이 실행된다.

			printf("*\t");
		}

		putchar('\n');
	}
}