#include <stdio.h>

void main(void)
{
	char* szName1[16] = { 'lee' };
	char szName2 = { 'lee' };

	printf("%d\n", sizeof(char*));		// 8
	printf("%d\n", sizeof(szName1));	// 128
	printf("%d\n", sizeof(szName2));	// 1
}
