#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void tt_main()
{
	int nData = 0;
	char szBuffer[128] = { 0 };
	FILE* fp = NULL;

	fp = fopen("fscanfTest.txt", "w");
	fprintf(fp, "%d,%s\n", 20, "Test");
	fclose(fp);


	fp = fopen("fscanfTest.txt", "r");
	fscanf(fp, "%c,%s", &nData, szBuffer);
	fclose(fp);

	printf("%d, %s\n", nData, szBuffer);
}