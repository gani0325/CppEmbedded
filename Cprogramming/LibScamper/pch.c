#define _CRT_SECURE_NO_WARNINGS
// pch.cpp: 미리 컴파일된 헤더에 해당하는 소스 파일
#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>

// 미리 컴파일된 헤더를 사용하는 경우 컴파일이 성공하려면 이 소스 파일이 필요합니다.
// 함수 정의

// 1) Scamper 문자열 대체해서 결합하기
char* Substitute(char* const  orgin, char* source, char* target) {
	char* szBuffer = malloc(strlen(orgin) * sizeof(orgin) + 1);
	memset(szBuffer, 0, strlen(orgin) * sizeof(orgin) + 1);

	char* source_ptr = orgin;
	char* target_ptr = szBuffer;

	while (*source_ptr) {

		// 1) 문자열 5개씩 비교하기	
		if (strncmp(source_ptr, source, strlen(source)) == 0) {
			strcpy(target_ptr, target);
			// 2) target 을 copy 하고 그다음 살펴볼 곳으로 포인터 이동
			target_ptr += strlen(target);
			source_ptr += strlen(source);
		}
		else {
			strncpy(target_ptr, source_ptr, 1);
			target_ptr++;
			source_ptr++;
		}

	}
	target_ptr = "/0";

	puts(szBuffer);
	return szBuffer;
}

// 2) sCamper 문자열 합치기
char* Combine(char* const  sourceA, char* const  sourceB) {
	char* szBuffer = malloc((strlen(sourceA) + strlen(sourceB)) * sizeof(sourceA) + 1);
	memset(szBuffer, 0, (strlen(sourceA) + strlen(sourceB)) * sizeof(sourceA) + 1);

	szBuffer = strcat(sourceA, sourceB);

	return szBuffer;
}

// 4) scaMper 소문자면 대문자, 대문자면 소문자
char* Modify(char* const  source, int chapital) { // 0=대문자, 1=소문자
	char* temp = malloc(strlen(source) + 1);
	memset(temp, 0, strlen(source) + 1);

	if (chapital == 0) {
		for (int i = 0; i < strlen(source); i++) {
			temp[i] = toupper(source[i]);
		}
	}
	else {
		for (int i = 0; i < strlen(source); i++) {
			temp[i] = tolower(source[i]);
		}
	}

	puts(temp);
	return temp;
}

// 7) scampeR 문자열 역순으로 배열하기
char* Reverse(char* const  source) {
	char* temp = malloc(strlen(source) + 1);
	memset(temp, 0, strlen(source) + 1);

	for (int i = 0; i < strlen(source); i++) {
		temp[i] = source[strlen(source) - 1 - i];
	}

	return temp;
}