#include <stdio.h>

void main()
{
	// 2번 문제의 코드를 수정하여 출력한 문자열이 저장된 메모리의 주소를 문자열 앞에 추가로 출력할 수 있게 하세요
	char ch[32] = { 0, };
	gets(ch);

	printf(ch);
	printf("\n%p", &ch);
}