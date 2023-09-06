#define _CRT_SECURE_NO_WARNINGS
// pch.cpp: 미리 컴파일된 헤더에 해당하는 소스 파일
#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>

// 5) scamPer 영어 이름을 이니셜로 요약해주기
char* PutToOtherUses(char* const  origin) {
	char* szBuffer = malloc(strlen(origin) * sizeof(origin) + 1);
	memset(szBuffer, 0, (strlen(origin) * sizeof(origin) + 1));
	int ch = 1;

	szBuffer[0] = origin[0];
	for (int i = 1; i < strlen(origin); i++) {
		if (origin[i] == ' ') {
			szBuffer[ch] = toupper(origin[i + 1]);
			ch++;
		}
		else {
			continue;
		}
	}
	return szBuffer;
}