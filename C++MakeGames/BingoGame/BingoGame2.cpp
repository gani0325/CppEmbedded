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

	int iBingo = 0;

	while (true) {
		system("cls");

		// 숫자를 5x5 출력
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (iNumber[i * 5 + j] == INT_MAX) {
					cout << "*\t";
				}
				else {
					cout << iNumber[i * 5 + j] << "\t";
				}
			}
			cout << endl;
		}

		cout << "Bingo Line : " << iBingo << endl;

		// 줄 수가 5 이상이면 게임 종료
		if (iBingo > 5) {
			break;
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

		// 빙고 줄 수 체크
		// 처음부터 새로 카운트 하기
		// iBingo 변수를 0으로 매번 초기화
		iBingo = 0;

		// 가로, 세로 줄 수
		int iStar1 = 0, iStar2 = 0;
		for (int i = 0; i < 5; ++i) {
			// 별 개수 0으로 초기화
			iStar1 = iStar2 = 0;

			for (int j = 0; j < 5; ++j) {
				// 가로 별 개수
				if (iNumber[i * 5 + j] == INT_MAX) {
					++iStar1;
				}

				// 세로 별 개수
				if (iNumber[j * 5 + i] == INT_MAX) {
					++iStar2;
				}
			}
			// 현재 줄의 가로 별 개수가 몇개인지 iStar1에 들어감
			// iStar1이 5이면 한줄이 모두 * 이므로 빙고 줄 카운트 증가
			if (iStar1 == 5) {
				++iBingo;
			}
			if (iStar2 == 5) {
				++iBingo;
			}
		}
		// 왼쪽 -> 아래쪽 하단 대각선
		iStar1 = 0;
		for (int i = 0; i < 25; i += 6) {
			if (iNumber[i] == INT_MAX) {
				++iStar1;
			}
		}
		if (iStar1 == 5) {
			++iBingo;
		}

		// 오른쪽 상단 -> 왼쪽 하단 대각선
		iStar1 = 0;
		for (int i = 4; i <= 20; i += 4) {
			if (iNumber[i] == INT_MAX) {
				++iStar1;
			}
		}
		if (iStar1 == 5) {
			++iBingo;
		}
	}
	return 0;
}