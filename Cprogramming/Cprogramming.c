﻿// 연산의 우선순위가 달라져서 결과가 달라짐

#include <stdio.h>

void main(void)
{
	// 사용자로부터 정수를 입력받고서 오른쪽 3비트의 값만 0으로 초기화하여 출력하는 프로그램을 작성하세요.
	// 예를 들어 사용자가 15를 입력했다면 8을 출력해야 합니다.
	// 단, 절대로 뺄셈 연산자를 사용하지 말고 AND 연산자(&)를 사용해야 합니다.

	int num;

	printf("숫자 입력 하세용 (num1) : ");
	scanf_s("%d", &num);

	printf("%d ", (num & 1000));
}
