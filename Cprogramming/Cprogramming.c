#include <stdio.h>

void main(void)
{
	// 사용자가 입력한 문자가 y이거나 Y이면 프로그램을 종료하고 아니면 계속해서 문자 하나를 입력받는 프로그램을 작성하세요.
	// 단, if 문과 goto 문을 사용하세요
	
	char ch;
	scanf_s("%c", &ch);

	if (ch == 'y' || ch == 'Y') {
		goto END;
	}		
	
	else {
		scanf_s("%c", &ch);
	}

END :
	printf("end");
}