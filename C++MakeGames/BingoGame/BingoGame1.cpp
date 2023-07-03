#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	srand((unsigned int)time(0));
	int iNumber[25] = {};

	// 1~25 숫자 넣기
	for (int i = 0; i < 25; i++) {
		iNumber[i] = i + 1;
	}
	// 숫자 섞기
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; ++i) {
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	while (true) {
		system("cls");

		// 숫자를 5x5 출력
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (iNumber[i * 5 + j] == INT_MAX) {
					cout << "*\t";
				}
				else {
					cout << iNumber[i * 5 + j] << "\t";				}
				}
			cout << endl;
		}

		cout << "숫자 입력 (종료 : 0) : ";
		int iInput;
		cin >> iInput;

		if (iInput == 0) {
			break;
		}
		else if (iInput < 1 || iInput > 25) {
			continue;
		}
		// 중복 입력 방지 체크
		bool bAcc = true;

		// 모든 숫자를 차례대로 검사
		// 입력한 숫자와 같은 숫자가 있는지 찾기
		for (int i = 0; i < 25; ++i) {
			// 같은 숫자
			if (iInput == iNumber[i]) {
				// 숫자 찾았을 경우 중복된 숫자 아님
				bAcc = false;

				// 숫자를 *로 변경하기 위한 특수 값 INT_MAX
				iNumber[i] = INT_MAX;
				// 찾아볼 숫자 없음
				break;
			}
		}
		// bAcc 변수가 true 일 경우 중복된 숫자 입력해서
		// 숫자를 *로 바꾸지 못했으므로 다시 입력받게 continue
		if (bAcc) {
			continue;
		}
	}
	return 0;
}