// Chapter1_9

#include <iostream>
using namespace std;

int main()
{
	// �����
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < i + 1; j++) {
			cout << "*";
		}
		cout << endl;
	}
	
	cout << endl;

	// �Ųٷ� �����
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5 - i; j++) {
			cout << "*";
		}
		cout << endl;
	}

	// �ﰢ�� �� ���
	// ����		��
		//3		1
		//2		3
		//1		5
		//0		7
	for (int i = 0; i < 4; i++) {
		// ������ ���� ��
		for (int j = 0; j < 3 - i; j++) {
			cout << " ";
		}
		// *�� ���� ��
		for (int j = 0; j < i * 2 + 1; j++) {
			cout << "*";
		}
		cout << endl;
	}
	
	return 0;
}