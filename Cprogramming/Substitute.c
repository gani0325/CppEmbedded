#define _CRT_SECURE_NO_WARNINGS
// pch.cpp: �̸� �����ϵ� ����� �ش��ϴ� �ҽ� ����
#include "pch.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

// ���̺귯���� �ش� main.c ���� ��ġ ���� �����Ŵ
#pragma comment(lib, "LibScamper")    //<<�ٸ� ���̺귯���� ���Ǿ����� �����Ϸ��� �˸��� �Բ� ��ũ


void Substitute_main() {
	// ���̺귯�� ���� - SCAMPER
	// 1) Scamper ���ڿ� ��ü�ؼ� ��ȯ�ϱ�
	char* const  orgin[20] = { 0 };
	char* source[20] = { 0 };
	char* target[20] = { 0 };

	printf("���� ���ڿ�");
	gets(orgin);
	printf("���� ���ڿ�");
	gets(source);
	printf("��ü�� ���ڿ�");
	gets(target);

	char* result1 = Substitute(&orgin, &source, &target);
	printf("Scamper ��� : ");
	printf("%s\n", result1);
	free(result1);
}