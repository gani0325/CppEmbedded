// <stdio.h> : 핵심 입력과 출력 함수들을 정의
#include <stdio.h>

void main()
{
	// getchar( ) 함수가 호출되었을 땐 
	// 키보드에 대한 입출력 버퍼가 비어 있는 상태
	char ch;
	ch = getchar();
	// putchar( )  문자를 모니터 화면에 출력하는 함수
	putchar(ch);
	ch = getchar();
	putchar(ch);
	ch = getchar();
	putchar(ch);
}

// TES