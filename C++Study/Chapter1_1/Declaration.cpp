#include <iostream>
// 헤더 사용하기
#include "add.h"

using namespace std;

int subtract(int a, int b);		// forward declaration

int main()
{
	cout << add(3, 4) << endl;
	cout << subtract(2, 3) << endl;
	return 0;
}

// definition
int add(int a, int b)
{
	return a + b;
}

int subtract(int a, int b)
{
	return a - b;
}