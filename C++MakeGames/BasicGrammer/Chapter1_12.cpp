// Chapter1_10

#include <iostream>
using namespace std;

int main()
{
	int Player1, Player2, Player3;	// 플레이어 3명
	int Computer1, Computer2, Computer3;	// 컴퓨터 3대
	int cnt = 1;
	int strike = 0;
	int ball = 0;

	srand((unsigned int)time(0));
	Computer1 = rand() % 9 + 1;
	Computer2 = rand() % 9 + 1;
	Computer3 = rand() % 9 + 1;

	cout << "숫자 야구 게임 시작" << endl;

	while (true) {
		cout << "1 ~ 9 숫자 입력 : " << endl;
		cin >> Player1;
		cin >> Player2;
		cin >> Player3;

		if (Computer1 == Player1) {
			strike++;
		}
		else if (Computer1 == Player2) {
			ball++;
		}
		else if (Computer1 == Player3) {
			ball++;
		}

		if (Computer2 == Player2) {
			strike++;
		}
		else if (Computer2 == Player1) {
			ball++;
		}
		else if (Computer2 == Player3) {
			ball++;
		}

		if (Computer3 == Player3) {
			strike++;
		}
		else if (Computer3 == Player1) {
			ball++;
		}
		else if (Computer3 == Player2) {
			ball++;
		}

		cout << "Strike : " << strike << endl;
		cout << "Ball : " << ball << endl;

		// strike 3번이면 아웃
		if (strike == 3) {
			break;
		}
		cnt++;
	}
	return 0;
}