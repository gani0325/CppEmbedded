#define _CRT_SECURE_NO_WARNINGS
// pch.cpp: 미리 컴파일된 헤더에 해당하는 소스 파일
#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>


// 3) scAmper 주어 받고 랜덤값으로 문자열 만들어주기
char* Adapt(char* const source) {
	char* szBuffer = malloc(strlen(source) * sizeof(source) + 15);
	memset(szBuffer, 0, (strlen(source) * sizeof(source) + 15));
	strcpy(szBuffer, source);

	// 난수값 설정
	srand((unsigned)time(NULL));
	int num = 0;
	num = rand() % 3;

	// 동사와 목적어
	char* verb[3] = { " think", " love", " look" };
	char* object[3] = { " book", " dog", " you" };

	// 문자열 합치기
	strcat(szBuffer, verb[num]);
	strcat(szBuffer, object[num]);

	return szBuffer;
}