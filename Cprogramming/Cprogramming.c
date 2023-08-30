#include <stdio.h>

void main(void)
{
	char aszName[2][16] = { "Gil-dong", "Ho-sung" };
	char(*pszName)[16] = aszName;

	printf("%c, %c\n", aszName[1][3], pszName[1][3]);
	printf("%p, %p\n", aszName, aszName + 1);
	printf("%p\n", *(aszName + 1) + 4);
	printf("%c\n", *(*(aszName + 1) + 4));
}

/*
s, s
0000002BA016F718, 0000002BA016F728
0000002BA016F72C
u
*/