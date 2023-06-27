// Chapter1_6

#include <iostream>
using namespace std;

int main()
{
	/*
	분기문에는 2가지 종류
	- if 문 : 조건을 체크해주는 기능
	if(조건식) {} 코드블럭
	조건식이 true 일 때 코드블럭 안의 코드 동작
	false 일 때 동작 X
	- switch 문
	*/
	if (true) {
		cout << "if 문 조건이 true 입니당" << endl;
	}
	int iNumber;
	cin >> iNumber;

	if (10 < iNumber) {
		cout << "10 보다 커용" << endl;
	}
	else if (5 < iNumber) {
		cout << "5 ~ 10 사이에용" << endl;
	}
	else {
		cout << "5 미만이에용" << endl;
	}
	return 0;
}