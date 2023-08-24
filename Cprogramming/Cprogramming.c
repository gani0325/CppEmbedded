#include <stdio.h>

void main()
{
	// 사용자로부터 정수를 입력받아 8진수와 16진수로 출력하는 프로그램을 작성하세요.
	// 단, 직접 변환하는 과정을 계산하지 말고 printf() 함수의 형식 문자를 활용하세요.
	int num=0;
	scanf_s("%d", &num);

	printf("%o\n", num);
	printf("%X", num);
}