// pch.cpp: 미리 컴파일된 헤더에 해당하는 소스 파일
#include "pch.h"
#include <stdio.h>

// 라이브러리를 해당 main.c 폴더 위치 내에 복사시킴
#pragma comment(lib, "LibScamper")    //<<다른 라이브러리가 사용되었음을 컴파일러에 알리고 함께 링크
void main() {
	PrintData(10);
	PrintString("Test string");
}