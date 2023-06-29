// Chapter1_10

#include <iostream>
using namespace std;

int main()
{
	srand((unsigned int)time(0));
	int iNumber[9] = {};

	// 1 ~ 9 숫자 설정
	for (int i = 0; i < 9; i++) {
		iNumber[i] = i + 1;
	}

	// 설정된 숫자 섞기
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; ++i) {
		idx1 = rand() % 9;
		idx2 = rand() % 9;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	cout << "*\t*\t*" << endl;
	//cout << iNumber[0] << "\t" << iNumber[1] << "\t" << iNumber[2] << endl;
	int iStrike = 0;
	int iBall = 0;
	int iInput[3] ;
	int iGameCnt = 1;

	while (true) {
		cout << iGameCnt << " 회" << endl;
		cout << "1 ~ 9 사이의 숫자 중 3개 입력 (0은 종료) : ";
		cin >> iInput[0] >> iInput[1] >> iInput[2];

		if (iInput[0] == 0 || iInput[1] == 0 || iInput[2] == 0) {
			break;
		}
		else if (iInput[0] < 0 || iInput[0] > 9 || iInput[1] < 0 || iInput[1] > 9 || iInput[2] < 0 || iInput[2] > 9) {
			cout << "잘못된 숫자 입력함" << endl;
			continue;
		}
		else if (iInput[0] == iInput[1] || iInput[1] == iInput[2] || iInput[0] == iInput[2]) {
			cout << "중복된 숫자 입력함" << endl;
			continue;
		}

		// 매번 Strike와 Ball 수가 달라지므로 0으로 초기화
		iStrike = iBall = 0;

		// 맞춰야할 숫자의 인덱스
		for (int i = 0; i < 3; ++i) {
			// 입력받은 숫자의 인덱스
			for (int j = 0; j < 3; ++j) {
				// 맞춰야할 숫자의 첫번째, 입력받은 숫자의 첫, 두, 세번째 비교해서 같은 값 찾기
				if (iNumber[i] == iInput[j]) {
					// 값이 같은 값이 있을 경우 Strike 아니면 Ball 이므로 자리 같은지 체크
					// i와 j 는 맞춰야할 숫자의 인덱스와 입력 받은 숫자의 인덱스

					// 인덱스가 서로 같다면 strike 증가, 아니라면 ball
					if (i == j)
						++iStrike;
					else
						++iBall;
					// 입력받은 숫자와 맞춰야할 숫자를 비교할 때 같은 수가 있으면
					// 더이상 같은 수는 없으므로 다음 맞춰야할 숫자로 바로 비교함
					break;
				}
			}
		}

		if (iStrike == 3) {
			cout << "숫자 모두 맞춤" << endl;
			break;
		}
		else if (iStrike == 0 && iBall == 0) {
			cout << "Out" << endl;
		}
		else {
			cout << iStrike << " Strike " << iBall << " Ball " << endl;
		}
		++iGameCnt;
	}

	return 0;
}