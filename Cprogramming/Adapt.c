#define _CRT_SECURE_NO_WARNINGS
// pch.cpp: 미리 컴파일된 헤더에 해당하는 소스 파일
#include "pch.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// 라이브러리를 해당 main.c 폴더 위치 내에 복사시킴
#pragma comment(lib, "LibScamper")    //<<다른 라이브러리가 사용되었음을 컴파일러에 알리고 함께 링크

void Adapt_main() {
	// 라이브러리 개발 - SCAMPER
	
	// 3) scAmper 주어 받고 랜덤값으로 문자열 만들어주기
	printf("주어 [ I, you , We ] 로 랜덤 문자 만들기 : ");
	char* sour[10] = { 0 };
	gets(sour);

	char* result3 = Adapt(sour);
	printf("scAmper 결과 : ");
	printf("%s\n", result3);
	free(result3);
}

/*
주어 [ I, you , We ] 로 랜덤 문자 만들기 : I
scAmper 결과 : I love dog
*/