#define _CRT_SECURE_NO_WARNINGS
// pch.cpp: 미리 컴파일된 헤더에 해당하는 소스 파일
#include "pch.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

// 라이브러리를 해당 main.c 폴더 위치 내에 복사시킴
#pragma comment(lib, "LibScamper")    //<<다른 라이브러리가 사용되었음을 컴파일러에 알리고 함께 링크

void main() {
	// 라이브러리 개발 - SCAMPER
	char* const  orgin[20] = { 0 };
	char* source[20] = {0};
	char* target[20] = {0};
	
	printf("원본 문자열");
	gets(orgin);
	printf("없앨 문자열");
	gets(source);
	printf("대체할 문자열");
	gets(target);
	
	char *result;
	result = Substitute(&orgin, &source, &target);
	printf("결과 : ");
	printf("%s", result);
}

/*
원본 문자열hello, world hello world
없앨 문자열hello
대체할 문자열hi
hi, world hi world
결과 : hi, world hi world
*/
