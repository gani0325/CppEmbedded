#include <iostream>
#include <time.h>
using namespace std;

enum AI_MODE {
	AM_EASY = 1,
	AM_HARD
};

enum LINE_NUMBER {
	LN_H1,
	LN_H2,
	LN_H3,
	LN_H4,
	LN_H5,
	LN_V1,
	LN_V2,
	LN_V3,
	LN_V4,
	LN_V5,
	LN_LT,
	LN_RT,
};

int main()
{
	srand((unsigned int)time(0));
	int iNumber[25] = {};
	int iAINumber[25] = {};


	// 1~25 숫자 넣기
	for (int i = 0; i < 25; i++) {
		iNumber[i] = i + 1;
		iAINumber[i] = i + 1;
	}
	// 숫자 섞기
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; ++i) {
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;

		// AI 숫자 섞기
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iAINumber[idx1];
		iAINumber[idx1] = iAINumber[idx2];
		iAINumber[idx2] = iTemp;

	}

	int iBingo = 0, iAIBingo = 0;
	int iAIMode;

	while (true) {
		system("cls");
		// AI 난이도
		cout << "1. Easy" << endl;
		cout << "2. Hard" << endl;
		cout << "AI 모드 선택하세요 : ";
		cin >> iAIMode;

		if (iAIMode >= AM_EASY && iAIMode <= AM_HARD) {
			break;
		}
	}

	// 선택 안된 목록 배열
	int iNoneSelect[25] = {};
	// 선택 안된 숫자 개수
	int iNoneSelectCount = 0;

	while (true) {
		system("cls");

		// 숫자를 5x5 출력
		cout << "########### Player ############" << endl;
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
		// Player 빙고 줄 수
		cout << "Bingo Line : " << iBingo << endl << endl;

		cout << "########### AI ############" << endl;

		switch (iAIMode) {
		case AM_EASY:
			cout << "AIMode : Easy" << endl;
			break;
		case AM_HARD:
			cout << "AIMode : Hard" << endl;
			break;
		}


		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (iAINumber[i * 5 + j] == INT_MAX) {
					cout << "*\t";
				}
				else {
					cout << iAINumber[i * 5 + j] << "\t";
				}
			}
			cout << endl;
		}

		// AI 빙고 줄 수
		cout << "AIBingo Line : " << iAIBingo << endl << endl;


		// 줄 수가 5 이상이면 게임 종료
		if (iBingo > 5) {
			cout << "Player 승리" << endl;
			break;
		}
		if (iAIBingo > 5) {
			cout << "AI 승리" << endl;
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

		// 중복 아니라면 AI의 숫자도 *로 바꾸기
		for (int i = 0; i < 25; ++i) {
			// 같은 숫자
			if (iInput == iAINumber[i]) {
				// 숫자를 *로 변경하기 위한 특수 값 INT_MAX
				iAINumber[i] = INT_MAX;
				// 찾아볼 숫자 없음
				break;
			}
		}

		// AI 모드에 다라 선택하는게 달라진다
		switch (iAIMode) {
			/*
			AI Easy : AI의 숫자목록 중 *로 바뀌지 않은 숫자 목록 만들어서
			그 목록 중 하나를 선택하게 함 (랜덤하게)
			*/
		case AM_EASY:
			// 선택 안된 숫자 목록 만들기
			// 선택 안된 숫자 개수는 목록을 만들 때 카운팅
			iNoneSelectCount = 0;
			for (int i = 0; i < 25; ++i) {
				// 현재 숫자가 *이 아닐 경우
				if (iAINumber[i] != INT_MAX) {
					// *이 아닌 숫자일 경우 iNoneSelectCount 인덱스로 활용
					// 총 선택 안된 개수 구하기
					iNoneSelect[iNoneSelectCount] = iAINumber[i];
					++iNoneSelectCount;
				}
			}

			// 선택 안된 목록의 개수 만들어짐
			// 선택 안된 목록의 숫자 중 랜덤한 하나의 숫자 얻어오기 위해 인덱스 랜덤하게 구하기
			iInput = iNoneSelect[rand() % iNoneSelectCount];
			break;
		case AM_HARD:
			// 현재 숫자 중 빙고줄 완성 가능성이 가장 높은 줄 찾아서
			// 그 줄에 있는 숫자 중 하나를 *로 만든다
			int iLine;
			int iStarCount = 0;
			int iSaveCount = 0;

			// 가로 라인 중 가장 *이 많은 줄 찾기
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (iAINumber[i * 5 + j] == INT_MAX) {
						++iStarCount;
					}
				}
				// 별이 5개 미만이어야 빙고 줄이 아니고,
				// 기존에 가장 많은 라인의 별보다 커야 가장 별이 많은 라인임
				// 라인 교체해주고 저장된 별 수 교체
				if (iStarCount < 5 && iSaveCount < iStarCount) {
					// 가로 라인 중 가장 별이 많은 라인 체크
					// 0~4로 의미 부여
					iLine = i;
					iSaveCount = iStarCount;
				}
			}

			// 가로 라인 중 가장 별이 많은 라인 구함
			// 세로 라인들을 비교하여 별이 가장 많은 라인 구한다
			// 세로 라인 중 가장 *이 많은 줄 찾기
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (iAINumber[i * 5 + j] == INT_MAX) {
						++iStarCount;
					}
				}
				
				if (iStarCount < 5 && iSaveCount < iStarCount) {
					// 세로라인은 5~9 로 의미 부여
					iLine = i + 5;
					iSaveCount = iStarCount;
				}
			}

			// 왼쪽 -> 오른쪽 대각선
			iStarCount = 0;
			for (int i = 0; i < 25; i += 6) {
				if (iAINumber[i] == INT_MAX) {
					++iStarCount;
				}
			}

			if (iStarCount < 5 && iSaveCount < iStarCount) {
				iLine = LN_LT;
				iSaveCount = iStarCount;
			}

			// 오른쪽 -> 왼쪽 대각선
			iStarCount = 0;
			for (int i = 4; i < 20; i += 4) {
				if (iAINumber[i] == INT_MAX) {
					++iStarCount;
				}
			}

			if (iStarCount < 5 && iSaveCount < iStarCount) {
				iLine = LN_RT;
				iSaveCount = iStarCount;
			}

			// iLine 에 가능성이 가장 높은 줄 번호 저장됨
			// 그 줄에 * 이 아닌 숫자중 하나 선택
			if (iLine <= LN_H5) {
				// 가로줄
				for (int i = 0; i < 5; ++i) {
					// *이 아닌 숫자
					if (iAINumber[iLine * 5 + i] != INT_MAX) {
						iInput = iAINumber[iLine * 5 + i];
						break;
					}
				}
			}
			else if (iLine <= LN_V5) {
				// 세로줄
				for (int i = 0; i < 5; ++i) {
					// *이 아닌 숫자
					if (iAINumber[i * 5 + iLine - 5] != INT_MAX) {
						iInput = iAINumber[i * 5 + iLine - 5];
						break;
					}
				}
			}
			else if (iLine <= LN_LT) {
				// 대각선
				for (int i = 0; i < 25; i += 6) {
					// *이 아닌 숫자
					if (iAINumber[i] != INT_MAX) {
						iInput = iAINumber[i];
						break;
					}
				}
			}
			else if (iLine <= LN_RT) {
				// 대각선
				for (int i = 4; i < 20; i += 4) {
					// *이 아닌 숫자
					if (iAINumber[i] != INT_MAX) {
						iInput = iAINumber[i];
						break;
					}
				}
			}

			break;
		}

		// AI 가 숫자 선택했으므로 플레이어와 AI의 숫자를 *로 바꾸기
		for (int i = 0; i < 25; ++i) {
			if (iNumber[i] == iInput) {
				iNumber[i] == INT_MAX;
				break;
			}
		}

		// AI 숫자 바꾸기
		for (int i = 0; i < 25; ++i) {
			if (iAINumber[i] == iInput) {
				iAINumber[i] == INT_MAX;
				break;
			}
		}
		// 빙고 줄 수 체크
		// 처음부터 새로 카운트 하기
		// iBingo 변수를 0으로 매번 초기화
		iBingo = 0;
		iAIBingo = 0;

		// 가로, 세로 줄 수
		int iStar1 = 0, iStar2 = 0;
		int iAIStar1 = 0, iAIStar2 = 0;

		for (int i = 0; i < 5; ++i) {
			// 별 개수 0으로 초기화
			iStar1 = iStar2 = 0;
			iAIStar1 = iAIStar2 = 0;

			for (int j = 0; j < 5; ++j) {
				// 가로 별 개수
				if (iNumber[i * 5 + j] == INT_MAX) {
					++iStar1;
				}

				// 세로 별 개수
				if (iNumber[j * 5 + i] == INT_MAX) {
					++iStar2;
				}

				// AI 가로 별 개수
				if (iAINumber[i * 5 + j] == INT_MAX) {
					++iAIStar1;
				}

				// AI 세로 별 개수
				if (iAINumber[j * 5 + i] == INT_MAX) {
					++iAIStar2;
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
			if (iAIStar1 == 5) {
				++iAIBingo;
			}
			if (iAIStar2 == 5) {
				++iAIBingo;
			}
		}
		// 왼쪽 -> 아래쪽 하단 대각선
		iStar1 = 0;
		iAIStar1 = 0;
		for (int i = 0; i < 25; i += 6) {
			if (iNumber[i] == INT_MAX) {
				++iStar1;
			}
			if (iAINumber[i] == INT_MAX) {
				++iAIStar1;
			}
		}
		if (iStar1 == 5) {
			++iBingo;
		}
		if (iAIStar1 == 5) {
			++iAIBingo;
		}

		// 오른쪽 상단 -> 왼쪽 하단 대각선
		iStar1 = 0;
		iAIStar1 = 0;
		for (int i = 4; i <= 20; i += 4) {
			if (iNumber[i] == INT_MAX) {
				++iStar1;
			}

			if (iAINumber[i] == INT_MAX) {
				++iAIStar1;
			}
		}
		if (iStar1 == 5) {
			++iBingo;
		}
		if (iAIStar1 == 5) {
			++iAIBingo;
		}
	}
	return 0;
}