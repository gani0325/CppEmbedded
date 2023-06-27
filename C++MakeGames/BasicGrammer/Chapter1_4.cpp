// Chapter1_4

#include <iostream>
using namespace std;

int main()
{
	/*
	진수
	2진수 : 0 ~ 1
	8진수 : 0 ~ 7
	10진수 : 0 ~ 9
	16진수 : 0~ 15 : a ~ f
	진수들은 서로 다른 진수로 변한 가능

	비트단위 논리연산자 : 2진수 단위의 연산 (값 대 값 연산하여 값으로 나옴)
	AND(&), OR(|), NOT(~), XOR(6)
	A	B	XOR
	0	0	0	
	1	0	1
	0	1	1
	1	1	0
	*/

	cout << "87 & 53 = " << (87 & 53) << endl;

	return 0;
}