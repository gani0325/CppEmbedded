#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h> 
void PrintData(int* array, int n)
{
	int i = 0;
	for (i = 0; i < n; ++i)
		printf("%d\t", array[i]);
	putchar('\n');
}

void BubbleAsc(int* array, int n) {
	// �������� 1) �������� -> (ū)
	int nTmp = 0;
	int* array2 = malloc(sizeof(int) * n);
	memcpy(array2, array, sizeof(int) * n);

	printf("%d", n);

	for (int i = n - 1; i >= 1; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (array[j] > array[j + 1])
			{
				nTmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = nTmp;
			}
		}
		PrintData(array, n);
	}
	printf("�������� 1) �������� -> (ū)\n");
	

	// �������� 2) �������� (��) <-
	for (int i = 4; i >= 1; --i)
	{
		for (int j = 4; j > 0; j--)
		{
			if (array2[j-1] > array2[j])
			{
				nTmp = array2[j-1];
				array2[j-1] = array2[j];
				array2[j] = nTmp;
			}
		}
		PrintData(array2, n);
	}
	printf("�������� 2) �������� (��) <-\n");
	
}

void BubbleDesc(int* array, int n) {
	// �������� 3) �������� -> (��)
	int nTmp = 0;
	int* array2 = malloc(sizeof(int) * n);
	memcpy(array2, array, sizeof(int) * n);

	for (int i = n - 1; i >= 1; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (array[j] < array[j + 1])
			{
				nTmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = nTmp;
			}
		}
		PrintData(array, n);
	}
	printf("�������� 3) �������� -> (��)\n");
	

	// �������� 4) �������� (��) <-
	for (int i = 4; i >= 1; --i)
	{
		for (int j = 4; j > 0; j--)
		{
			if (array2[j - 1] < array2[j])
			{
				nTmp = array2[j - 1];
				array2[j - 1] = array2[j];
				array2[j] = nTmp;
			}
		}
		PrintData(array2, n);
	}
	printf("�������� 4) �������� (��) <-\n");
	
}

void main()
{
	int n = 0;

	printf("�迭�� ������ ���� �־��ּ��� : ");
	scanf_s("%d", &n);

	int * anData = (int *)malloc(sizeof(int)*n);
	//memset(anData, 0, malloc(sizeof(int) * n));

	printf("�迭�ϰ� ���� ���� �־��ּ��� : ");
	int j = 0;
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &anData[i]);
	}
	puts(anData);

	BubbleAsc(anData, n);
	BubbleDesc(anData, n);
	free(anData);
}

/*
�������� 1) �������� -> (ū)
2       4       1       3       5
2       1       3       4       5
1       2       3       4       5
1       2       3       4       5

�������� 2) �������� (��) <-
1       4       2       5       3
1       2       4       3       5
1       2       3       4       5
1       2       3       4       5

�������� 3) �������� -> (��)
4       5       2       3       1
5       4       3       2       1
5       4       3       2       1
5       4       3       2       1

�������� 4) �������� (��) <-
5       4       2       3       1
5       4       3       2       1
5       4       3       2       1
5       4       3       2       1

*/