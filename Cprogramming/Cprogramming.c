#include <stdio.h>

void main()
{
	// 사용자로부터 음수 하나를 입력받아 printf( ) 함수를 이용하여 부호가 없는 정수형과 16진수로 출력하는 프로그램을 작성하세요.
	// 단, 출력되는 두 값은 각각 다른 행에 출력되어야 합니다
	int num = 0;

	scanf_s("%d", &num);
	printf("%u\n", num);
	printf("%x", num);
}