#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	srand((unsigned int)time(0));
	int iNumber[25] = {};

	// 1~25 ���� �ֱ�
	for (int i = 0; i < 25; i++) {
		iNumber[i] = i + 1;
	}
	// ���� ����
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

		// ���ڸ� 5x5 ���
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

		// �� ���� 5 �̻��̸� ���� ����
		if (iBingo > 5) {
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

		// ���� �� �� üũ
		// ó������ ���� ī��Ʈ �ϱ�
		// iBingo ������ 0���� �Ź� �ʱ�ȭ
		iBingo = 0;

		// ����, ���� �� ��
		int iStar1 = 0, iStar2 = 0;
		for (int i = 0; i < 5; ++i) {
			// �� ���� 0���� �ʱ�ȭ
			iStar1 = iStar2 = 0;

			for (int j = 0; j < 5; ++j) {
				// ���� �� ����
				if (iNumber[i * 5 + j] == INT_MAX) {
					++iStar1;
				}

				// ���� �� ����
				if (iNumber[j * 5 + i] == INT_MAX) {
					++iStar2;
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
		}
		// ���� -> �Ʒ��� �ϴ� �밢��
		iStar1 = 0;
		for (int i = 0; i < 25; i += 6) {
			if (iNumber[i] == INT_MAX) {
				++iStar1;
			}
		}
		if (iStar1 == 5) {
			++iBingo;
		}

		// ������ ��� -> ���� �ϴ� �밢��
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