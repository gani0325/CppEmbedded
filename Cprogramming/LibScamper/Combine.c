#define _CRT_SECURE_NO_WARNINGS
// pch.cpp: 미리 컴파일된 헤더에 해당하는 소스 파일
#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>

// 2) sCamper 문자열 합치기
char* Combine(char* const  sourceA, char* const  sourceB) {
	char* szBuffer = malloc((strlen(sourceA) + strlen(sourceB)) * sizeof(sourceA) + 1);
	memset(szBuffer, 0, (strlen(sourceA) + strlen(sourceB)) * sizeof(sourceA) + 1);

	szBuffer = strcat(sourceA, sourceB);

	return szBuffer;
}