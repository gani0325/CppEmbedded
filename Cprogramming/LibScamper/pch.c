#define _CRT_SECURE_NO_WARNINGS
// pch.cpp: 미리 컴파일된 헤더에 해당하는 소스 파일
#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>

// 미리 컴파일된 헤더를 사용하는 경우 컴파일이 성공하려면 이 소스 파일이 필요합니다.
// 함수 정의
char* Combine(char* const  sourceA, char* const  sourceB) {
	char* szBuffer = malloc((strlen(sourceA) + strlen(sourceB)) * sizeof(sourceA) + 1);
	memset(szBuffer, 0, (strlen(sourceA) + strlen(sourceB)) * sizeof(sourceA) + 1);

	szBuffer = strcat(sourceA, sourceB);

	return szBuffer;
}