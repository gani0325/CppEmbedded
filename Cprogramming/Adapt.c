#define _CRT_SECURE_NO_WARNINGS
// pch.cpp: �̸� �����ϵ� ����� �ش��ϴ� �ҽ� ����
#include "pch.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// ���̺귯���� �ش� main.c ���� ��ġ ���� �����Ŵ
#pragma comment(lib, "LibScamper")    //<<�ٸ� ���̺귯���� ���Ǿ����� �����Ϸ��� �˸��� �Բ� ��ũ

void Adapt_main() {
	// ���̺귯�� ���� - SCAMPER
	
	// 3) scAmper �־� �ް� ���������� ���ڿ� ������ֱ�
	printf("�־� [ I, you , We ] �� ���� ���� ����� : ");
	char* sour[10] = { 0 };
	gets(sour);

	char* result3 = Adapt(sour);
	printf("scAmper ��� : ");
	printf("%s\n", result3);
	free(result3);
}

/*
�־� [ I, you , We ] �� ���� ���� ����� : I
scAmper ��� : I love dog
*/