#define _CRT_SECURE_NO_WARNINGS
// pch.cpp: 미리 컴파일된 헤더에 해당하는 소스 파일
#include "pch.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

// 라이브러리를 해당 main.c 폴더 위치 내에 복사시킴
#pragma comment(lib, "LibScamper")    //<<다른 라이브러리가 사용되었음을 컴파일러에 알리고 함께 링크

void Reverse_main() {
	// 라이브러리 개발 - SCAMPER

	// 7) scampeR 문자열 역순으로 배열하기
	printf("역순할 문자열 : ");
	char* reverse[20] = { 0, };
	gets(reverse);

	char* result3 = Reverse(reverse);
	printf("scampeR 결과 : ");
	printf("%s\n", result3);
	free(result3);
}
