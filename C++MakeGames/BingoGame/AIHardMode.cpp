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


	// 1~25 ���� �ֱ�
	for (int i = 0; i < 25; i++) {
		iNumber[i] = i + 1;
		iAINumber[i] = i + 1;
	}
	// ���� ����
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; ++i) {
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;

		// AI ���� ����
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
		// AI ���̵�
		cout << "1. Easy" << endl;
		cout << "2. Hard" << endl;
		cout << "AI ��� �����ϼ��� : ";
		cin >> iAIMode;

		if (iAIMode >= AM_EASY && iAIMode <= AM_HARD) {
			break;
		}
	}

	// ���� �ȵ� ��� �迭
	int iNoneSelect[25] = {};
	// ���� �ȵ� ���� ����
	int iNoneSelectCount = 0;

	while (true) {
		system("cls");

		// ���ڸ� 5x5 ���
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
		// Player ���� �� ��
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

		// AI ���� �� ��
		cout << "AIBingo Line : " << iAIBingo << endl << endl;


		// �� ���� 5 �̻��̸� ���� ����
		if (iBingo > 5) {
			cout << "Player �¸�" << endl;
			break;
		}
		if (iAIBingo > 5) {
			cout << "AI �¸�" << endl;
			break;
		}

		cout << "���� �Է� (���� : 0) : ";
		int iInput;
		cin >> iInput;

		if (iInput == 0) {
			break;
		}
		else if (iInput < 1 || iInput > 25) {
			continue;
		}
		// �ߺ� �Է� ���� üũ
		bool bAcc = true;

		// ��� ���ڸ� ���ʴ�� �˻�
		// �Է��� ���ڿ� ���� ���ڰ� �ִ��� ã��
		for (int i = 0; i < 25; ++i) {
			// ���� ����
			if (iInput == iNumber[i]) {
				// ���� ã���� ��� �ߺ��� ���� �ƴ�
				bAcc = false;

				// ���ڸ� *�� �����ϱ� ���� Ư�� �� INT_MAX
				iNumber[i] = INT_MAX;
				// ã�ƺ� ���� ����
				break;
			}
		}
		// bAcc ������ true �� ��� �ߺ��� ���� �Է��ؼ�
		// ���ڸ� *�� �ٲ��� �������Ƿ� �ٽ� �Է¹ް� continue
		if (bAcc) {
			continue;
		}

		// �ߺ� �ƴ϶�� AI�� ���ڵ� *�� �ٲٱ�
		for (int i = 0; i < 25; ++i) {
			// ���� ����
			if (iInput == iAINumber[i]) {
				// ���ڸ� *�� �����ϱ� ���� Ư�� �� INT_MAX
				iAINumber[i] = INT_MAX;
				// ã�ƺ� ���� ����
				break;
			}
		}

		// AI ��忡 �ٶ� �����ϴ°� �޶�����
		switch (iAIMode) {
			/*
			AI Easy : AI�� ���ڸ�� �� *�� �ٲ��� ���� ���� ��� ����
			�� ��� �� �ϳ��� �����ϰ� �� (�����ϰ�)
			*/
		case AM_EASY:
			// ���� �ȵ� ���� ��� �����
			// ���� �ȵ� ���� ������ ����� ���� �� ī����
			iNoneSelectCount = 0;
			for (int i = 0; i < 25; ++i) {
				// ���� ���ڰ� *�� �ƴ� ���
				if (iAINumber[i] != INT_MAX) {
					// *�� �ƴ� ������ ��� iNoneSelectCount �ε����� Ȱ��
					// �� ���� �ȵ� ���� ���ϱ�
					iNoneSelect[iNoneSelectCount] = iAINumber[i];
					++iNoneSelectCount;
				}
			}

			// ���� �ȵ� ����� ���� �������
			// ���� �ȵ� ����� ���� �� ������ �ϳ��� ���� ������ ���� �ε��� �����ϰ� ���ϱ�
			iInput = iNoneSelect[rand() % iNoneSelectCount];
			break;
		case AM_HARD:
			// ���� ���� �� ������ �ϼ� ���ɼ��� ���� ���� �� ã�Ƽ�
			// �� �ٿ� �ִ� ���� �� �ϳ��� *�� �����
			int iLine;
			int iStarCount = 0;
			int iSaveCount = 0;

			// ���� ���� �� ���� *�� ���� �� ã��
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (iAINumber[i * 5 + j] == INT_MAX) {
						++iStarCount;
					}
				}
				// ���� 5�� �̸��̾�� ���� ���� �ƴϰ�,
				// ������ ���� ���� ������ ������ Ŀ�� ���� ���� ���� ������
				// ���� ��ü���ְ� ����� �� �� ��ü
				if (iStarCount < 5 && iSaveCount < iStarCount) {
					// ���� ���� �� ���� ���� ���� ���� üũ
					// 0~4�� �ǹ� �ο�
					iLine = i;
					iSaveCount = iStarCount;
				}
			}

			// ���� ���� �� ���� ���� ���� ���� ����
			// ���� ���ε��� ���Ͽ� ���� ���� ���� ���� ���Ѵ�
			// ���� ���� �� ���� *�� ���� �� ã��
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (iAINumber[i * 5 + j] == INT_MAX) {
						++iStarCount;
					}
				}
				
				if (iStarCount < 5 && iSaveCount < iStarCount) {
					// ���ζ����� 5~9 �� �ǹ� �ο�
					iLine = i + 5;
					iSaveCount = iStarCount;
				}
			}

			// ���� -> ������ �밢��
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

			// ������ -> ���� �밢��
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

			// iLine �� ���ɼ��� ���� ���� �� ��ȣ �����
			// �� �ٿ� * �� �ƴ� ������ �ϳ� ����
			if (iLine <= LN_H5) {
				// ������
				for (int i = 0; i < 5; ++i) {
					// *�� �ƴ� ����
					if (iAINumber[iLine * 5 + i] != INT_MAX) {
						iInput = iAINumber[iLine * 5 + i];
						break;
					}
				}
			}
			else if (iLine <= LN_V5) {
				// ������
				for (int i = 0; i < 5; ++i) {
					// *�� �ƴ� ����
					if (iAINumber[i * 5 + iLine - 5] != INT_MAX) {
						iInput = iAINumber[i * 5 + iLine - 5];
						break;
					}
				}
			}
			else if (iLine <= LN_LT) {
				// �밢��
				for (int i = 0; i < 25; i += 6) {
					// *�� �ƴ� ����
					if (iAINumber[i] != INT_MAX) {
						iInput = iAINumber[i];
						break;
					}
				}
			}
			else if (iLine <= LN_RT) {
				// �밢��
				for (int i = 4; i < 20; i += 4) {
					// *�� �ƴ� ����
					if (iAINumber[i] != INT_MAX) {
						iInput = iAINumber[i];
						break;
					}
				}
			}

			break;
		}

		// AI �� ���� ���������Ƿ� �÷��̾�� AI�� ���ڸ� *�� �ٲٱ�
		for (int i = 0; i < 25; ++i) {
			if (iNumber[i] == iInput) {
				iNumber[i] == INT_MAX;
				break;
			}
		}

		// AI ���� �ٲٱ�
		for (int i = 0; i < 25; ++i) {
			if (iAINumber[i] == iInput) {
				iAINumber[i] == INT_MAX;
				break;
			}
		}
		// ���� �� �� üũ
		// ó������ ���� ī��Ʈ �ϱ�
		// iBingo ������ 0���� �Ź� �ʱ�ȭ
		iBingo = 0;
		iAIBingo = 0;

		// ����, ���� �� ��
		int iStar1 = 0, iStar2 = 0;
		int iAIStar1 = 0, iAIStar2 = 0;

		for (int i = 0; i < 5; ++i) {
			// �� ���� 0���� �ʱ�ȭ
			iStar1 = iStar2 = 0;
			iAIStar1 = iAIStar2 = 0;

			for (int j = 0; j < 5; ++j) {
				// ���� �� ����
				if (iNumber[i * 5 + j] == INT_MAX) {
					++iStar1;
				}

				// ���� �� ����
				if (iNumber[j * 5 + i] == INT_MAX) {
					++iStar2;
				}

				// AI ���� �� ����
				if (iAINumber[i * 5 + j] == INT_MAX) {
					++iAIStar1;
				}

				// AI ���� �� ����
				if (iAINumber[j * 5 + i] == INT_MAX) {
					++iAIStar2;
				}
			}
			// ���� ���� ���� �� ������ ����� iStar1�� ��
			// iStar1�� 5�̸� ������ ��� * �̹Ƿ� ���� �� ī��Ʈ ����
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
		// ���� -> �Ʒ��� �ϴ� �밢��
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

		// ������ ��� -> ���� �ϴ� �밢��
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