// Chapter1_9

#include <iostream>
using namespace std;

int main()
{
	// 별찍기
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < i + 1; j++) {
			cout << "*";
		}
		cout << endl;
	}
	
	cout << endl;

	// 거꾸로 별찍기
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5 - i; j++) {
			cout << "*";
		}
		cout << endl;
	}

	// 삼각형 별 찍기
	// 공백		별
		//3		1
		//2		3
		//1		5
		//0		7
	for (int i = 0; i < 4; i++) {
		// 공백을 위한 문
		for (int j = 0; j < 3 - i; j++) {
			cout << " ";
		}
		// *을 위한 문
		for (int j = 0; j < i * 2 + 1; j++) {
			cout << "*";
		}
		cout << endl;
	}
	
	return 0;
}