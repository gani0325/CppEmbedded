#define _CRT_SECURE_NO_WARNINGS
// pch.cpp: 미리 컴파일된 헤더에 해당하는 소스 파일
#include "pch.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

// 라이브러리를 해당 main.c 폴더 위치 내에 복사시킴
#pragma comment(lib, "LibScamper")    //<<다른 라이브러리가 사용되었음을 컴파일러에 알리고 함께 링크

void Eliminate_main() {
	// 라이브러리 개발 - SCAMPER

	// 6) scampEr 타겟 문자있으면 제거하기
	char* sourA[20] = { 0 };
	char* sourB[20] = { 0 };

	printf("제거하기 위한 문자열 : ");
	gets(sourA);
	printf("제거할 문자 : ");
	gets(sourB);

	char* result5 = Eliminate(sourA, sourB);
	printf("scampEr 결과 : ");
	printf("%s\n", result5);
	free(result5);
}

/*
제거하기 위한 문자열 : gHello gani
제거할 문자 : g
scampEr 결과 : Hello ani
*/