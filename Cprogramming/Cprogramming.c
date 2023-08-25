#include <stdio.h>

void main(void)
{
	// 사용자로부터 입력받은 두 정수가 모두 10보다 크면 1을 출력하고 
	// 그렇지 않은 경우(둘중 하나라도 10보다 작거나 같은 경우) 0을 출력하는 프로그램을 작성하세요

	int num1, num2;
	printf("숫자 입력하세용 (num1, num2) : ");
	scanf_s("%d %d", &num1, &num2);

	if (num1 > 10 && num2 > 10) {
		printf("%d", 1);
	}
	else {
		printf("%d", 0);
	}
}