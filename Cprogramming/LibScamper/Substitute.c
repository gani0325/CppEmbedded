#define _CRT_SECURE_NO_WARNINGS
// pch.cpp: �̸� �����ϵ� ����� �ش��ϴ� �ҽ� ����
#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>

// �̸� �����ϵ� ����� ����ϴ� ��� �������� �����Ϸ��� �� �ҽ� ������ �ʿ��մϴ�.
// �Լ� ����

// 1) Scamper ���ڿ� ��ü�ؼ� �����ϱ�
char* Substitute(char* const  orgin, char* source, char* target) {
	char* szBuffer = malloc(strlen(orgin) * sizeof(orgin) + 1);
	memset(szBuffer, 0, strlen(orgin) * sizeof(orgin) + 1);

	char* source_ptr = orgin;
	char* target_ptr = szBuffer;

	while (*source_ptr) {

		// 1) ���ڿ� 5���� ���ϱ�	
		if (strncmp(source_ptr, source, strlen(source)) == 0) {
			strcpy(target_ptr, target);
			// 2) target �� copy �ϰ� �״��� ���캼 ������ ������ �̵�
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