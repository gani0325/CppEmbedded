#include <stdio.h>
#include <malloc.h>

void main(void)
{
	// 사용자로부터 정수를 입력받은 후, 그 정수의 크기만큼(바이트 단위) 메모리를 동적으로
	// 할당받고 0으로 초기화하는 프로그램을 작성하세요.
	// 단, 정수의 값이 100을 초과하면 강제로 100으로 조정하고, 10보다 작은 경우에는 10으로 조정합니다.

	int num;
	int* pnNum = NULL;
	scanf_s("%d", &num);
	printf("%d", num);

	if (num > 100) {
		pnNum = (int*)malloc(sizeof(int) * 100);
		memset(pnNum, 0, sizeof(int) * 100);
	}
	else if (num < 10) {
		pnNum = (int*)malloc(sizeof(int) * 10);
		memset(pnNum, 0, sizeof(int) * 10);
	}
	else {
		pnNum = (int*)malloc(sizeof(int) * num);
		memset(pnNum, 0, sizeof(int) * num);
	}

	free(pnNum);
}

/*

*/