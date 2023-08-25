// 연산의 우선순위가 달라져서 결과가 달라짐

#include <stdio.h>

void main(void)
{
	// 사용자로부터 양의 정수(초)를 입력받아 시:분:초 형태로 출력하는 프로그램을 작성하세요.
	// 이 문제를 해결하려면 나눗셈 연산자(/ )와 나머지 연산자(%)를 활용할 수 있어야 합니다
	int num;

	printf("숫자 입력 하세용 (num1) : ");
	scanf_s("%d", &num);

	int time = num / 3600;
	int minute = (num % 3600) / 60;
	int count = (num % 3600) % 60;

	printf("%d:%d:%d", time, minute, count);
}
