#define _CRT_SECURE_NO_WARNINGS
// pch.cpp: 미리 컴파일된 헤더에 해당하는 소스 파일
#include "pch.h"
#include <stdio.h>
#include <string.h>
// 미리 컴파일된 헤더를 사용하는 경우 컴파일이 성공하려면 이 소스 파일이 필요합니다.


char* szBuffer[20] = { 0 };
char* Substitute(char* const  orgin, char* source, char* target) {
	
	char temp[20] = { 0 };
	char* source_ptr = orgin;
	char* target_ptr = temp;

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

	//szBuffer = malloc(strlen(temp) + 1);
	memcpy(szBuffer, temp, 20);
	puts(szBuffer);
	return szBuffer;
}