// Chapter1_8

#include <iostream>
using namespace std;

/*
����ü : ���ӵ� ���ڿ� �̸� �ο��ϴ� ���
enum ����ü�� {}
����ü�� �̿��ؼ� ����ü Ÿ���� ���� ���� ����
��, ����ü ��ü�� ����� ���� ���� Ÿ�� �� �� ����
����ü�� ���ڿ� �̸��� �ٿ��ִ� ���
*/
enum NUM
{
	NUM_0,	// �ƹ��͵� �ο����� ���� ��� 0���� 1�� ���ʷ� �� �ο�
	NUM_1,
	NUM_2,
	NUM_3
};

int main()
{
	/*
	- switch �� : �б⹮�� �� ����
	���� ������ üũ�ϴ� �б⹮
	switch(����) {} �ڵ��
	�ڵ� �� �ȿ��� case break ������ ��
	case ��� : �� ���·� ó���� ��
	�������� ���������� ���� case �ڿ� ���� ��� ��
	*/
	int iNumber;
	cout << "���� �Է� : ";
	cin >> iNumber;

	switch (iNumber) {
	case 1:		// iNumber ���� �����ΰ��� ���� ����Ǵ� case ���� ����
		cout << "�Է��� ���ڴ� 1" << endl;
		break;	// break ������ switch �� ����������
	case 2:
		cout << "�Է��� ���ڴ� 2" << endl;
		// break ���� ���, �ٷ� �Ʒ� �ִ� case ���� ���� ����
	case 3:
		cout << "�Է��� ���ڴ� 3" << endl;
		break;
	case 4:
		cout << "�Է��� ���ڴ� 4" << endl;
		break;
	default:	// case �� �������� ���� ��� ����ȴ�
		cout << "�� �� �����Դϴ�" << endl;
		break;
	}
	return 0;
}