#define _CRT_SECURE_NO_WARNINGS
// pch.cpp: �̸� �����ϵ� ����� �ش��ϴ� �ҽ� ����
#include "pch.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

// ���̺귯���� �ش� main.c ���� ��ġ ���� �����Ŵ
#pragma comment(lib, "LibScamper")    //<<�ٸ� ���̺귯���� ���Ǿ����� �����Ϸ��� �˸��� �Բ� ��ũ

void Reverse_main() {
	// ���̺귯�� ���� - SCAMPER

	// 7) scampeR ���ڿ� �������� �迭�ϱ�
	printf("������ ���ڿ� : ");
	char* reverse[20] = { 0, };
	gets(reverse);

	char* result3 = Reverse(reverse);
	printf("scampeR ��� : ");
	printf("%s\n", result3);
	free(result3);
}
