// Chapter1_3

#include <iostream>
using namespace std;

int main()
{
	/*
	��Ģ ������ : +, -, *, /, % (������ ������)
	���� ������ : >, >=, <, <=, ==, != (�� �� ���� �����Ͽ� ��/�������� ��� ��ȯ)
	*/
	cout << "10 < 20 " << (10 < 20) << endl;
	cout << "40 < 20 " << (40 < 20) << endl;

	/*
	�� ������ : ��/���� �� ��/���� �����Ͽ� ��/�������� ��� ��ȯ
	AND(&&), OR(||), NOT(!)
	A	B	AND	OR
	0	0	0	0
	1	0	0	1
	0	1	0	1
	1	1	1	1
	
	A	NOT
	1	0
	0	1
	*/
	int Number;
	cout << "���� �Է��ϼ��� : ";
	cin >> Number;

	cout << "10 ~ 20 = " << (10 <= Number && Number <= 20) << endl;
		
	return 0;
}