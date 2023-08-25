#include <stdio.h>

void main(void)
{
	// 사용자로부터 영문 한 글자와 정수 둘을 입력받은 후, 영문 한 글자가 무엇인지에 따라
	// 다음과 같은 연산을 수행하고 결과를 출력하는 프로그램을 작성하세요.
	//	a : 두 수를 더함
	//	b : 두 수를 곱함
	//	c : 먼저 입력된 정수에서 나중에 입력한 정수를 뺌
	// 만일 이중 어느 것에도 해당하지 않는 영문자가 입력되었다면, 다음처럼「알 수 없는 명령」
	// 이라는 문자열을 출력하고서 프로그램은 종료되어야 합니다

	char ch;
	int num1 = 0, num2 = 0;
	printf("영문 한 글자와 정수 둘을 입력하세용 (ch num1 num2) : ");
	scanf_s("%c", &ch);
	scanf_s("%d %d", &num1, &num2);

	if (ch == 'a') {
		printf("%d + %d = %d", num1, num2, num1 + num2);
	} else if (ch == 'b') {
		printf("%d * %d = %d", num1, num2, num1 * num2);
	} else if (ch == 'c') {
		printf("%d - %d = %d", num1, num2, num1 - num2);
	} else {
		printf("「알 수 없는 명령」");
	}
}

