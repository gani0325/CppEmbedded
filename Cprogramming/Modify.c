#define _CRT_SECURE_NO_WARNINGS
// pch.cpp: �̸� �����ϵ� ����� �ش��ϴ� �ҽ� ����
#include "pch.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

// ���̺귯���� �ش� main.c ���� ��ġ ���� �����Ŵ
#pragma comment(lib, "LibScamper")    //<<�ٸ� ���̺귯���� ���Ǿ����� �����Ϸ��� �˸��� �Բ� ��ũ

void Modify_main() {
	// ���̺귯�� ���� - SCAMPER
	// 4) scaMper �ҹ��ڸ� �빮��, �빮�ڸ� �ҹ���
	char* sourA4[10] = { 0, };
	int changeNum = 0;

	printf("���ĺ� ���� ��ȯ�ϱ� (���� �Է�, 0=�빮�� 1=�ҹ���) : ");
	gets(sourA4);
	scanf_s("%d", &changeNum);

	char* result4 = Modify(sourA4, changeNum);
	printf("sCamper ��� : ");
	printf("%s\n", result4);
	free(result4);
}