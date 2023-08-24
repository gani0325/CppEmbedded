#include <stdio.h>

void main()
{
	// 두 실수를 입력받아 평균을 구하고서 소수점 이하 둘째 자리까지 출력하는 프로그램을 작성하세요.
	// 단, 소수점 이하 셋째 자리가 절사되거나 반올림되는 것은 전혀 고려하지 않아도 좋습니다.
	float num1 = 0;
	float num2 = 0;

	scanf_s("%f %f", &num1, &num2);
	printf("%.2f", (num1 + num2) / 2);
}