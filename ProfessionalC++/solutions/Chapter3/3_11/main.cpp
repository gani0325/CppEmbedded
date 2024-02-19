// 헤더 파일과 cpp 파일로 분리하기
// main.cpp
#include "Calculator.h"

int main()
{
    // calc 객체 생성
    Calculator calc;
    calc.run();
}

/*
- 헤더 파일과 cpp 파일 분리
클래스마다 선언부는 헤더 파일에, 구현부는 cpp 파일에 분리하여 작성
mian() 등 함수나 전역 변수는 한 개 이상의 cpp 파일에 나누어 작성한다
클래스마다 클래스의 선언부와 구현부를 헤더 파일과 cpp 소스 파일로 분리하면 전체 프로그램을 관리하기 쉽고 클래스를 재사용하기 쉽다

ex) 바람직한 C++ 프로그램 작성법
Circle.h : Circle 클래스 선언부
Circle.cpp : Circle 클래스 구현부
main.cpp : main() 함수 등 나머지 코드로

- 헤더 파일을 중복 include 할 때 문제점
cpp 파일에 클래스가 선언된 헤더 파일을 여러 번 include 하면 , 중복 선언으로 인해 컴파일 오류가 발생한다
헤더 파일을 중복 include 해도 컴파일 오류가 발생하지 않도록 Circle.h 헤더 파일에 조건 컴파일 문을 삽입한다
*/