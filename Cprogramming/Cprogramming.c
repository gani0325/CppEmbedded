#include <stdio.h>

void main()
{
	// gets( ) 함수로 문자열을 입력받고서 printf( ) 함수를 호출하여 같은 문자열을 화면에 출력하세요
	// 단, 문자열의 최대 길이는 영문 32자 미만이라고 가정합니다.
	char ch[32] = { 0, };
	gets(ch);

	printf(ch);
}