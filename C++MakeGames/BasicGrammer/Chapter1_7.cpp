// Chapter1_7

#include <iostream>
using namespace std;

int main()
{
	// 난수 발생
	srand((unsigned int)time(0));
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	
	// 0 ~ 99 사이의 난수를 얻고 싶다면? 나누기해보자!
	cout << (rand() % 101) << endl;

	// 100 ~ 200 사이의 난수를 얻고 싶다면? 나누기해보자!
	cout << (rand() % 101 + 100) << endl;

	// 강화 확률
	int iUpgrade = 0;
	cout << "Upgrade 기본 수치 입력하세요 : ";
	cin >> iUpgrade;
	
	float fPercent = rand() % 10000 / 100.f;
	// 업그레이드가 0 ~ 3 : 100 % 성공
	// 4 ~ 6 : 40 % 성공
	// 7 ~ 9 : 10 % 성공
	// 10 ~ 13 : 1 % 성공
	// 14 ~ 15 : 0.01 % 성공
	cout << "Upgrade : " << iUpgrade << endl;
	cout << "Percent : " << fPercent << endl;

	if (iUpgrade <= 3) {
		cout << "강화 성공" << endl;
	}
	else if (4 <= iUpgrade && iUpgrade <= 6) {
		if (fPercent < 40.f) {
			cout << "강화 성공" << endl;
		}
		else {
			cout << "강화 실패" << endl;
		}
	}
	else if (7 <= iUpgrade && iUpgrade <= 9) {
		if (fPercent < 10.f) {
			cout << "강화 성공" << endl;
		}
		else {
			cout << "강화 실패" << endl;
		}
	}
	else if (10 <= iUpgrade && iUpgrade <= 13) {
		if (fPercent < 1.f) {
			cout << "강화 성공" << endl;
		}
		else {
			cout << "강화 실패" << endl;
		}
	}
	else if (14 <= iUpgrade && iUpgrade <= 15) {
		if (fPercent < 0.01f) {
			cout << "강화 성공" << endl;
		}
		else {
			cout << "강화 실패" << endl;
		}
	}
	return 0;
}