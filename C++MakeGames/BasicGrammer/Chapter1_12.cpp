// Chapter1_10

#include <iostream>
using namespace std;

int main()
{
	srand((unsigned int)time(0));
	int iNumber[9] = {};

	// 1 ~ 9 ���� ����
	for (int i = 0; i < 9; i++) {
		iNumber[i] = i + 1;
	}

	// ������ ���� ����
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
		cout << iGameCnt << " ȸ" << endl;
		cout << "1 ~ 9 ������ ���� �� 3�� �Է� (0�� ����) : ";
		cin >> iInput[0] >> iInput[1] >> iInput[2];

		if (iInput[0] == 0 || iInput[1] == 0 || iInput[2] == 0) {
			break;
		}
		else if (iInput[0] < 0 || iInput[0] > 9 || iInput[1] < 0 || iInput[1] > 9 || iInput[2] < 0 || iInput[2] > 9) {
			cout << "�߸��� ���� �Է���" << endl;
			continue;
		}
		else if (iInput[0] == iInput[1] || iInput[1] == iInput[2] || iInput[0] == iInput[2]) {
			cout << "�ߺ��� ���� �Է���" << endl;
			continue;
		}

		// �Ź� Strike�� Ball ���� �޶����Ƿ� 0���� �ʱ�ȭ
		iStrike = iBall = 0;

		// ������� ������ �ε���
		for (int i = 0; i < 3; ++i) {
			// �Է¹��� ������ �ε���
			for (int j = 0; j < 3; ++j) {
				// ������� ������ ù��°, �Է¹��� ������ ù, ��, ����° ���ؼ� ���� �� ã��
				if (iNumber[i] == iInput[j]) {
					// ���� ���� ���� ���� ��� Strike �ƴϸ� Ball �̹Ƿ� �ڸ� ������ üũ
					// i�� j �� ������� ������ �ε����� �Է� ���� ������ �ε���

					// �ε����� ���� ���ٸ� strike ����, �ƴ϶�� ball
					if (i == j)
						++iStrike;
					else
						++iBall;
					// �Է¹��� ���ڿ� ������� ���ڸ� ���� �� ���� ���� ������
					// ���̻� ���� ���� �����Ƿ� ���� ������� ���ڷ� �ٷ� ����
					break;
				}
			}
		}

		if (iStrike == 3) {
			cout << "���� ��� ����" << endl;
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