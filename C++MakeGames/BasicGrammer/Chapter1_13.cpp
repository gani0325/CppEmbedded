// Chapter1_13

#include <iostream>
#include <time.h>
// console input output ��� ����
// �ܼ�â���� ����� �ϴ� �������
#include <conio.h>
using namespace std;

int main()
{
	srand((unsigned int)time(0));
	int iNumber[25] = {};

	for (int i = 0; i < 24; ++i) {
		iNumber[i] = i + 1;
	}
	// ���� ������ ĭ�� �������� �����
	// ���� �ǹ̸� INT_MAX ����! �̹� ���ǵ� �ִ밪
	iNumber[24] = INT_MAX;

	// �� �ִ� ��ġ�� ������ ����
	int iStarIndex = 24;

	// 1~24 ���ڸ� ����
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
		// ������
		for (int i = 0; i < 5; ++i) {
			// ������
			for (int j = 0; j < 5; ++j) {
				// i�� 0�� �� 0~4���� �ݺ�
				// i�� 1�� �� 5~9���� �ݺ�
				// i�� 2�� �� 10~14���� �ݺ�
				// i�� 3�� �� 15~19���� �ݺ�
				// i�� 4�� �� 20~24���� �ݺ�
				// �ٹ�ȣ * ���� ���� + ĭ ��ȣ
				cout << iNumber[i * 5 + j] << "\t";
			}
			cout << endl;
		}
		
		// true �� ���� ��� ����� ��� ����
		bool bWin = true;
		// ���� ���߾����� üũ
		for (int i = 0; i < 24; ++i) {
			if (iNumber[i] != i + 1) {
				bWin = false;
				break;
			}
		}

		if (bWin == true) {
			cout << "���� ��� ����" << endl;
			break;
		}
		cout << "w : �� s : �Ʒ� a : ���� d : ������ q : ���� : ";
		// _getch() : ���� 1�� �Է¹޴� �Լ� (���� ������ ���� �ٷ� �� ���� ��ȯ�ϰ� ����)
		char cInput = _getch();
		if (cInput == 'q' || cInput == 'Q') {
			break;
		}		

		switch (cInput) {
		case 'w':
		case 'W':
				// ���� ���ٿ��� w ������ ���� �ö󰡸� �ȵ�
				if (iStarIndex > 4) {
					// �� �ִ� ��ġ�� �ٷ� ���� �ִ� �� �ֱ�
					iNumber[iStarIndex] = iNumber[iStarIndex - 5];
					// ���� ��ġ�� �� �ְ� 2���� �� ���� ��ü
					iNumber[iStarIndex - 5] = INT_MAX;
					// �� ��ĭ �ö����Ƿ� ��ĭ ���� �ε����� �����
					iStarIndex -= 5;
				}
			break;
		case 's':
		case 'S':
				// ���� �Ʒ����� �ƴ� ��� ������
				if (iStarIndex < 20) {
					// �� �ִ� ��ġ�� �ٷ� ���� �ִ� �� �ֱ�
					iNumber[iStarIndex] = iNumber[iStarIndex + 5];
					// ���� ��ġ�� �� �ְ� 2���� �� ���� ��ü
					iNumber[iStarIndex + 5] = INT_MAX;
					// �� ��ĭ �ö����Ƿ� ��ĭ ���� �ε����� �����
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
	cout << "������ �����մϴ�" << endl;
	return 0;
}