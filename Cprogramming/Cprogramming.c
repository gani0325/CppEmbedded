// 연산의 우선순위가 달라져서 결과가 달라짐

#include <stdio.h>

void main(void)
{
	// 사용자로부터 정수 두 개를 입력받고 사칙 연산(덧셈, 뺄셈, 곱셈, 나눗셈) 결과를 출력
	// 예를 들어 10과 5를 입력받았다면 15, 5, 50, 2가 출력되어야 합니다.
	int num1, num2;

	printf("숫자 입력 하세용 (num1 num2) : ");
	scanf_s("%d %d", &num1, &num2);

	printf("%d + %d = %d", num1, num2, num1 + num2);
	printf("\n%d - %d = %d", num1, num2, num1 - num2);
	printf("\n%d * %d = %d", num1, num2, num1 * num2);
	printf("\n%d / %d = %d", num1, num2, num1 / num2);
}
