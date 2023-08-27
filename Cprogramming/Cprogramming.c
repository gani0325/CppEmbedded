// 배열의 이름을 포인터 변수에 담아서 사용

#include <stdio.h>

void main(void)
{
	char szName[16] = { 0 };
	char* pszName = szName;

	sprintf(pszName, "%s", "홍길동");
	puts(szName);
}

/*
홍길동
*/