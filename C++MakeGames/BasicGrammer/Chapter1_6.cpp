// Chapter1_6

#include <iostream>
using namespace std;

int main()
{
	/*
	�б⹮���� 2���� ����
	- if �� : ������ üũ���ִ� ���
	if(���ǽ�) {} �ڵ��
	���ǽ��� true �� �� �ڵ�� ���� �ڵ� ����
	false �� �� ���� X
	- switch ��
	*/
	if (true) {
		cout << "if �� ������ true �Դϴ�" << endl;
	}
	int iNumber;
	cin >> iNumber;

	if (10 < iNumber) {
		cout << "10 ���� Ŀ��" << endl;
	}
	else if (5 < iNumber) {
		cout << "5 ~ 10 ���̿���" << endl;
	}
	else {
		cout << "5 �̸��̿���" << endl;
	}
	return 0;
}