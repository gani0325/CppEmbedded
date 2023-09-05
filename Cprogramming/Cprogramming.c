#define _CRT_SECURE_NO_WARNINGS
// pch.cpp: 미리 컴파일된 헤더에 해당하는 소스 파일
#include "pch.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

// 라이브러리를 해당 main.c 폴더 위치 내에 복사시킴
#pragma comment(lib, "LibScamper")    //<<다른 라이브러리가 사용되었음을 컴파일러에 알리고 함께 링크

void main() {
	// 라이브러리 개발 - SCAMPER
	// 1) Scamper 문자열 대체해서 변환하기
	//char* const  orgin[20] = { 0 };
	//char* source[20] = { 0 };
	//char* target[20] = { 0 };

	//printf("원본 문자열");
	//gets(orgin);
	//printf("없앨 문자열");
	//gets(source);
	//printf("대체할 문자열");
	//gets(target);

	//char* result1 = Substitute(&orgin, &source, &target);
	//printf("Scamper 결과 : ");
	//printf("%s\n", result1);

	//// 2) sCamper 문자열 합치기
	//char* sourA[20] = { 0 };
	//char* sourB[20] = { 0 };

	//printf("결합하고 싶은 문자 : ");
	//gets(sourA);
	//gets(sourB);

	//char* result2 = Combine(sourA, sourB);
	//printf("sCamper 결과 : ");
	//printf("%s\n", result2);
	
	// 4) scaMper 소문자면 대문자, 대문자면 소문자
	char* sourA4[10] = { 0, };
	int changeNum = 0;

	printf("알파벳 형태 변환하기 (문자 입력, 0=대문자 1=소문자) : ");
	gets(sourA4);
	scanf_s("%d", &changeNum);

	char* result4 = Modify(sourA4, changeNum);
	printf("sCamper 결과 : ");
	printf("%s\n", result4);

	//// 7) scampeR 문자열 역순으로 배열하기
	//printf("역순할 문자열 : ");
	//char* reverse[20] = { 0, };
	//gets(reverse);

	//char* result3 = Reverse(reverse);
	//printf("scampeR 결과 : ");
	//printf("%s\n", result3);
}


/*
원본 문자열hello, world hello world
없앨 문자열hello
대체할 문자열hi
hi, world hi world
결과 : hi, world hi world

알파벳 형태 변환하기 (문자 입력, 0=대문자 1=소문자) : HeLlo
1
hello
sCamper 결과 : hello

*/
