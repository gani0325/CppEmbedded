#include <iostream>
using namespace std;

#define NAME_SIZE	64
/*
����ü : �����ִ� �������� ��Ƽ� �ϳ��� ���ο� Ÿ���� ������ִ� ���
����� ���� ���� Ÿ��
struct ����ü�� {};

�迭�� ����ü�� ������ :
1. ������ ����
2. ���ӵ� �޸� ���� �Ҵ��
����ü ������� ���ӵ� �޸� ������ ����

*/

struct _tagStudent {
	char	strName[NAME_SIZE];
	int		iNumber;
	int		iKor;
	int		iEng;
	int		iMath;
	int		iTotal;
	float	fAvg;
};
int main() {
	_tagStudent tStudent = {};
	_tagStudent tStudentArr[100] = {};

	// ����ü ����� ������ �� .�̿��ؼ� ����
	tStudent.iKor = 100;

	// strcpy_s �Լ� �̿��ؼ� ���ڿ� �����ϱ�
	// �����ʿ� �ִ� ���ڿ��� �������� ����
	// ���ڿ��� ���� �׻� 0(null)�� ������ �Ѵ�
	// �� �迭��ҿ� �� �־��ָ� �� �� ���
	// �־����� ���� �� �κ��� �����Ⱚ ���
	// strcpy_s �� �ڵ����� ���� �׻� 0(null) �־���
	strcpy_s(tStudent.strName, "�����ٶ� abcd");

	// strcat_s �Լ��� ���ڿ��� �ٿ��ִ� ���
	strcat_s(tStudent.strName, "���ڿ� ���̱�");

	// strcmp �Լ��� �� ���ڿ��� ���Ͽ� ���� ��� 0 ��ȯ
	// �ٸ� ��� 0�� �ƴ� �� ��ȯ
	strcmp(tStudent.strName, "ȫ�浿");

	// strlen �Լ��� ���ڿ� ����
	strlen(tStudent.strName);

	cout << "���� �̸� : ";
	char strName[NAME_SIZE] = {};
	cin >> strName;

	strcpy_s(tStudent.strName, "����");

	if (strcmp(tStudent.strName, strName) == 0) {
		cout << "�л� ã��" << endl;
	}
	else {
		cout << "�л� ����" << endl;
	}

	cout << "�̸� : " << tStudent.strName << endl;
	cout << "�й� : " << tStudent.iNumber << endl;
	cout << "���� : " << tStudent.iKor << endl;
	cout << "���� : " << tStudent.iEng << endl;
	cout << "���� : " << tStudent.iMath << endl;
	cout << "���� : " << tStudent.iTotal << endl;
	cout << "��� : " << tStudent.fAvg << endl;
	return 0;;
}