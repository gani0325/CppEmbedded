// Chapter1_8

#include <iostream>
using namespace std;

int main()
{
	/*
	for �� : �ݺ����� �� ����
	for (�ʱⰪ; ���ǽ�; ������) {}

	���ǽ��� true �̸� �ڵ���� �ڵ尡 ���۵�
	���ѷ����� for(;;) {} 

	for ������ �ʱⰪ�� ó�� for ���� ������ �� �� 1�� ����
	�� �� ���ǽ��� üũ�ϰ� true �̸� �ڵ尡 ���۵� �� ������ ó��
	���� �ٽ� ���� üũ�ϰ� true ���� -> ���� -> ���� -> ����
	������ false �̳� break ������ for �� ��������	
	*/

	// ���� ���̺�
	srand((unsigned int)time(0));
	int iPlayer, iAI;
	
	while (false) {
		system("cls");
		cout << "1. ����" << endl;
		cout << "2. ����" << endl;
		cout << "3. ��" << endl;
		cout << "4. ����" << endl;
		cout << "�޴� �����ϼ���" << endl;
		cin >> iPlayer;
	}

	// ������ 2��
	for (int i = 1; i < 9; ++i) {
		cout << "2 * " << i << "= " << 2 * i << endl;
	}

	// 1 ~ 100 ���� �� ¦���� ����ϴ� for ��
	for (int i = 1; i < 100; i++) {
		if (i % 2 == 0) {
			cout << i << endl;
		}
	}
	// 1 ~ 100 ���� �� 3�� 7 ������� ����ϴ� if ��
	for (int i = 1; i <= 100; ++i) {
		if (i % 3 == 0 && i % 7 == 0) {
			cout << i << endl;
		}
	}
	return 0;
}