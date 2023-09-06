#define _CRT_SECURE_NO_WARNINGS
// pch.cpp: 미리 컴파일된 헤더에 해당하는 소스 파일
#include "pch.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

// 라이브러리를 해당 main.c 폴더 위치 내에 복사시킴
#pragma comment(lib, "LibScamper")    //<<다른 라이브러리가 사용되었음을 컴파일러에 알리고 함께 링크


void Combine_main() {
	// 라이브러리 개발 - SCAMPER

	// 2) sCamper 문자열 합치기
	char* sourA[20] = { 0 };
	char* sourB[20] = { 0 };

	printf("결합하고 싶은 문자 : ");
	gets(sourA);
	gets(sourB);

	char* result2 = Combine(sourA, sourB);
	printf("sCamper 결과 : ");
	printf("%s\n", result2);
	free(result2);
}