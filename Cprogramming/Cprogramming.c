#include <stdio.h>

void main(void)
{
	int x = 0, y = 0;
	while (y < 5)
	{
		x = 0;
		while (x < 4)
		{
			printf("*\t");
			x++;
		}
		putchar('\n');
		y++;
	}
} // x값의 증가는 열의 증가로 y값의 증가는 행의 증가를 나타낸다.
/*
*       *       *       *
*       *       *       *
*       *       *       *
*       *       *       *
*       *       *       *
*/