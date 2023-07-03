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

	while (true) {
		system("cls");

		// ���ڸ� 5x5 ���
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
	}
	return 0;
}