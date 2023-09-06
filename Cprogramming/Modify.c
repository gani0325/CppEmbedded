#define _CRT_SECURE_NO_WARNINGS
// pch.cpp: 미리 컴파일된 헤더에 해당하는 소스 파일
#include "pch.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

// 라이브러리를 해당 main.c 폴더 위치 내에 복사시킴
#pragma comment(lib, "LibScamper")    //<<다른 라이브러리가 사용되었음을 컴파일러에 알리고 함께 링크

void Modify_main() {
	// 라이브러리 개발 - SCAMPER
	// 4) scaMper 소문자면 대문자, 대문자면 소문자
	char* sourA4[10] = { 0, };
	int changeNum = 0;

	printf("알파벳 형태 변환하기 (문자 입력, 0=대문자 1=소문자) : ");
	gets(sourA4);
	scanf_s("%d", &changeNum);

	char* result4 = Modify(sourA4, changeNum);
	printf("sCamper 결과 : ");
	printf("%s\n", result4);
	free(result4);
}