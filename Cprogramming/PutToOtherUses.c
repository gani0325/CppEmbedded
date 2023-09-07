#define _CRT_SECURE_NO_WARNINGS
// pch.cpp: 미리 컴파일된 헤더에 해당하는 소스 파일
#include "pch.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

void main() {
	// 라이브러리 개발 - SCAMPER

	// 5) scamPer 영어 이름을 이니셜로 요약해주기
	char* name[20] = { 0, };
	printf("영어 이름 (이니셜로 요약) : ");
	gets(name);

	char* result5 = PutToOtherUses(name);
	printf("scamPer 결과 : ");
	printf("%s\n", result5);
	free(result5);
}