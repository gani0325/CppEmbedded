#include <stdio.h>
#include <malloc.h>

void main(void)
{
	//  두 정수를 입력받아 같은 숫자인지 아닌지 비교하는 프로그램을 작성하세요.
	//  단, == 연산자가 아니라 memcmp() 함수를 사용하세요

	int num1[] = { 0 };
	int num2[] = { 0 };
	//int* ptrnum1 = &num1, ptrnum2 = &num2;

	scanf_s("%d %d", &num1, &num2);

	if (memcmp(num1, num2, 10) == 0) {
		printf("%d %d 같은 수", *num1, *num2);
	}
	else if (memcmp(num1, num2, 10) == 1) {
		printf("%d > %d", *num1, *num2);
	}
	else if (memcmp(num1, num2, 10) == -1) {
		printf("%d < %d", *num1, *num2);
	}
}

/*

*/