// Chapter1_9

#include <iostream>
using namespace std;

int main()
{
	// ���̾Ƹ��� �� ���
	int iLine = 7;
	int iCnt = 0;

	for (int i = 0; i < iLine; i++) {
		// ���� : 3 2 1 0 1 2 3
		// �� : 1 3 5 7 5 3 1
		iCnt = i;

		// i���� 4, 5, 6 �϶��� ��
		if (i > iLine / 2) {
			iCnt = iLine - 1 - i;
		}

		// i���� 0, 1, 2, 3 �϶��� �״�� iCnt ����
		// i���� 4, 5, 6 �϶��� iCnt 2, 1, 0 ����
		// ��, i�� 0, 1, 2, 3, 2, 1, 0

		for (int j = 0; j < 3 - iCnt; j++) {
			cout << " ";
		}

		for (int j = 0; j < iCnt * 2 + 1; j++) {
			cout << "*";
		}

		cout << endl;
	}
	return 0;
}