#define _CRT_SECURE_NO_WARNINGS
// pch.cpp: �̸� �����ϵ� ����� �ش��ϴ� �ҽ� ����
#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>

// 7) scampeR ���ڿ� �������� �迭�ϱ�
char* Reverse(char* const  source) {
	char* temp = malloc(strlen(source) + 1);
	memset(temp, 0, strlen(source) + 1);

	for (int i = 0; i < strlen(source); i++) {
		temp[i] = source[strlen(source) - 1 - i];
	}

	return temp;
}