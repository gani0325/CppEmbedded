// 연산의 우선순위가 달라져서 결과가 달라짐

#include <stdio.h>

void main(void)
{
	// 사용자로부터 정수를 입력받아 5로 나눈 나머지를 출력하는 프로그램을 작성하세요
	int num;

	printf("숫자 입력 하세용 (num1) : ");
	scanf_s("%d", &num);

	printf("%d %% 5 = %d", num, num % 5);
}
