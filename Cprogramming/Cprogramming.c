#include <stdio.h>

void main(void)
{
	// 사용자로부터 세 정수를 입력받고, 그 중에서 가장 큰 정수를 출력하는 프로그램을 작성하세요
	// 단, 반드시 삼항 연산자를 사용하세요

	int num1 = 0, num2 = 0 , num3 = 0;
	printf("세 정수를 입력하세용 (num1, num2, num3) : ");
	scanf_s("%d %d %d", &num1, &num2, &num3);

	int temp, result;
	temp = (num1 > num2) ? num1 : num2;
	result = (temp > num3) ? temp : num3;

	printf("%d", result);
}