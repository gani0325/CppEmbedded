#define _CRT_SECURE_NO_WARNINGS
// pch.cpp: 미리 컴파일된 헤더에 해당하는 소스 파일
#include "pch.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

// 라이브러리를 해당 main.c 폴더 위치 내에 복사시킴
#pragma comment(lib, "LibScamper")    //<<다른 라이브러리가 사용되었음을 컴파일러에 알리고 함께 링크

void PutToOtherUses_main() {
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