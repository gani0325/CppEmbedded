// Chapter1_13

#include <iostream>
#include <time.h>
// console input output 헤더 파일
// 콘솔창에서 입출력 하는 헤더파일
#include <conio.h>
using namespace std;

int main()
{
	srand((unsigned int)time(0));
	int iNumber[25] = {};

	for (int i = 0; i < 24; ++i) {
		iNumber[i] = i + 1;
	}
	// 가장 마지막 칸은 공백으로 비워둠
	// 공백 의미를 INT_MAX 으로! 이미 정의된 최대값
	iNumber[24] = INT_MAX;

	// 별 있는 위치를 저장할 변수
	int iStarIndex = 24;

	// 1~24 숫자만 섞기
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; ++i) {
		idx1 = rand() % 24;
		idx2 = rand() % 24;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}
	while (true) {
		system("cls");
		// 세로줄
		for (int i = 0; i < 5; ++i) {
			// 가로줄
			for (int j = 0; j < 5; ++j) {
				// i가 0일 때 0~4까지 반복
				// i가 1일 때 5~9까지 반복
				// i가 2일 때 10~14까지 반복
				// i가 3일 때 15~19까지 반복
				// i가 4일 때 20~24까지 반복
				// 줄번호 * 가로 개수 + 칸 번호
				cout << iNumber[i * 5 + j] << "\t";
			}
			cout << endl;
		}
		
		// true 로 먼저 모두 맞췄다 라고 가정
		bool bWin = true;
		// 퍼줄 맞추었는지 체크
		for (int i = 0; i < 24; ++i) {
			if (iNumber[i] != i + 1) {
				bWin = false;
				break;
			}
		}

		if (bWin == true) {
			cout << "숫자 모두 맞춤" << endl;
			break;
		}
		cout << "w : 위 s : 아래 a : 왼쪽 d : 오른쪽 q : 종료 : ";
		// _getch() : 문자 1개 입력받는 함수 (문자 누르는 순간 바로 그 문자 반환하고 종료)
		char cInput = _getch();
		if (cInput == 'q' || cInput == 'Q') {
			break;
		}		

		switch (cInput) {
		case 'w':
		case 'W':
				// 가장 윗줄에는 w 눌러도 위로 올라가면 안됨
				if (iStarIndex > 4) {
					// 별 있는 위치에 바로 위에 있는 값 넣기
					iNumber[iStarIndex] = iNumber[iStarIndex - 5];
					// 위에 위치에 별 넣고 2개의 값 서로 교체
					iNumber[iStarIndex - 5] = INT_MAX;
					// 별 한칸 올라갔으므로 한칸 위의 인덱스로 만들기
					iStarIndex -= 5;
				}
			break;
		case 's':
		case 'S':
				// 가장 아래줄이 아닐 경우 움직임
				if (iStarIndex < 20) {
					// 별 있는 위치에 바로 위에 있는 값 넣기
					iNumber[iStarIndex] = iNumber[iStarIndex + 5];
					// 위에 위치에 별 넣고 2개의 값 서로 교체
					iNumber[iStarIndex + 5] = INT_MAX;
					// 별 한칸 올라갔으므로 한칸 위의 인덱스로 만들기
					iStarIndex += 5;
				}
			break;
		case 'a':
		case 'A':
				if (iStarIndex % 5 != 0) {
					iNumber[iStarIndex] = iNumber[iStarIndex - 1];
					iNumber[iStarIndex - 1] = INT_MAX;
					--iStarIndex;
				}
			break;
		case 'd':
		case 'D':
				if (iStarIndex % 5 != 4) {
					iNumber[iStarIndex] = iNumber[iStarIndex + 1];
					iNumber[iStarIndex + 1] = INT_MAX;
					++iStarIndex;
				}
			break;
		}
	}
	cout << "게임을 종료합니당" << endl;
	return 0;
}