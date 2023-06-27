// Chapter1_8

#include <iostream>
using namespace std;

int main()
{
	/*
	for 문 : 반복문의 한 종류
	for (초기값; 조건식; 증감값) {}

	조건식이 true 이면 코드블럭의 코드가 동작됨
	무한루프는 for(;;) {} 

	for 문에서 초기값은 처음 for 문에 진입할 때 딱 1번 동작
	그 후 조건식을 체크하고 true 이면 코드가 동작된 후 증감값 처리
	그후 다시 조건 체크하고 true 동작 -> 증감 -> 조건 -> 증감
	조건이 false 이나 break 마나면 for 문 빠져나감	
	*/

	// 난수 테이블
	srand((unsigned int)time(0));
	int iPlayer, iAI;
	
	while (false) {
		system("cls");
		cout << "1. 가위" << endl;
		cout << "2. 바위" << endl;
		cout << "3. 보" << endl;
		cout << "4. 종료" << endl;
		cout << "메뉴 선택하셈요" << endl;
		cin >> iPlayer;
	}

	// 구구단 2단
	for (int i = 1; i < 9; ++i) {
		cout << "2 * " << i << "= " << 2 * i << endl;
	}

	// 1 ~ 100 사이 중 짝수만 출력하는 for 문
	for (int i = 1; i < 100; i++) {
		if (i % 2 == 0) {
			cout << i << endl;
		}
	}
	// 1 ~ 100 사이 중 3과 7 공배수만 출력하는 if 문
	for (int i = 1; i <= 100; ++i) {
		if (i % 3 == 0 && i % 7 == 0) {
			cout << i << endl;
		}
	}
	return 0;
}