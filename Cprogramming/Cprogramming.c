// 연산의 우선순위가 달라져서 결과가 달라짐

#include <stdio.h>

void main(void)
{
	// 사용자로부터 정수를 입력받아 부호를 변환하여 출력하는 프로그램을 작성하세요. 
	// 예를 들어 3을 입력했다면 - 3을, -20을 입력했다면 20을 출력해야 합니다.

	int num;

	printf("숫자 입력 하세용 (num1) : ");
	scanf_s("%d", &num);

	printf("%d => %d", num, (~num) + 1);
}
