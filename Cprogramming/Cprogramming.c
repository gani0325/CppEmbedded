﻿#include <stdio.h>

int main(void) {
	char a[] = "Art";
	char* p = NULL;
	p = a;
	printf("%s\n", a);
	printf("%c\n", *p);
	printf("%c\n", *a);
	printf("%s\n", a);

	for (int i = 0; a[i] != '\0'; i++) {
		printf("%c", a[i]);
	}
}

// 정보처리기사 기출 문제
//Art
//A
//A
//Art
//Art