// <stdio.h> : 핵심 입력과 출력 함수들을 정의
#include <stdio.h>
#include <conio.h>

void main()
{
	char ch;
	// getch() 함수는 정말 문자 하나만을 입력받는다
	// 표준 입력 장치의 파일 버퍼를 거치지도 않는다
	ch = _getch();
	printf("%c\n", ch);

	// getche( ) 함수는 마치 메아리 (echo) 처럼 
	// 사용자가 입력한 키보드의 값을 화면에 출력
	ch = _getche();
	printf("%c\n", ch);
}

// a
// bb 