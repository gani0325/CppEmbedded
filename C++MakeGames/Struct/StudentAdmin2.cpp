#include <iostream>
using namespace std;

#define NAME_SIZE		64
#define STUDENT_MAX		10
#define ADDRESS_SIZE	238
#define PHONE_SIZE		14

struct _tagStudent {
	char	strName[NAME_SIZE];
	char	strAddress[ADDRESS_SIZE];
	char	strPhoneNumber[PHONE_SIZE];
	int		iNumber;
	int		iKor;
	int		iEng;
	int		iMath;
	int		iTotal;
	float	fAvg;
};

enum MENU {
	MENU_NEXT,
	MENU_INSERT,
	MENU_DELETE,
	MENU_SEARCH,
	MENU_OUTPUT,
	MENU_EXIT
};

int main() {
	_tagStudent tStudentArr[STUDENT_MAX] = {};

	// �迭�� �߰��� ������ ������ ���� �����
	int iStudentCount = 0;
	int iStdNumber = 0;

	char strName[NAME_SIZE] = {};

	while (true) {
		system("cls");

		// �޴� ���
		cout << "1. �л����" << endl;
		cout << "2. �л�����" << endl;
		cout << "3. �л�Ž��" << endl;
		cout << "4. �л����" << endl;
		cout << "5. ����" << endl;
		cout << "�޴��� �����ϼ��� : ";
		int iMenu;
		cin >> iMenu;

		//���� : �ӽ��������
		//cin ���ο� �Է¹��۰� �ִµ� �Է¹��۴� �Է��� ���� �����ϰ�
		//�� ���� ������ �־��ִ� ����
		//���� üũ�ϰ�, cin.fail() ���� �� �Է� ������ �߻��ϸ� true ��ȯ
		if (cin.fail()) {
			// �������� ����
			cin.clear();

			// �Է¹��ۿ� \n�� ���������Ƿ� �Է¹��۸� �˻��Ͽ� \n �����
			// ù��°�� �˻��ϰ��� �ϴ� ���� ũ�� ���� (�˳��ϰ� 1024 byte)
			// ã���� �ϴ� ���� �ֱ�
			cin.ignore(1024, '\n');
			continue;
		}

		if (iMenu == MENU_EXIT)
			break;

		switch (iMenu) {
		case MENU_INSERT:
			system("cls");
			cout << "#################### �л��߰� ###################" << endl;
			// �ִ� ���ġ ������ �߰��ϱ�
			if (iStudentCount == STUDENT_MAX)
				break;
			// �л� ���� �߰�
			// �̸�, �ּ�, ��ȭ��ȣ
			// ����, ����, ���� ������ �Է¹ް� �й�, ����, ����� ����
			// �̸� �Է¹ޱ�
			cout << "�̸� : ";
			cin >> tStudentArr[iStudentCount].strName;

			cin.ignore(1024, '\n');
			cout << "�ּ� : ";
			cin.getline(tStudentArr[iStudentCount].strAddress, ADDRESS_SIZE);

			cout << "��ȭ��ȣ : ";
			cin.getline(tStudentArr[iStudentCount].strPhoneNumber, PHONE_SIZE);

			cout << "���� : ";
			cin >> tStudentArr[iStudentCount].iKor;

			cout << "���� : ";
			cin >> tStudentArr[iStudentCount].iEng;

			cout << "���� : ";
			cin >> tStudentArr[iStudentCount].iMath;

			tStudentArr[iStudentCount].iTotal =
				tStudentArr[iStudentCount].iKor +
				tStudentArr[iStudentCount].iEng +
				tStudentArr[iStudentCount].iMath;
			tStudentArr[iStudentCount].fAvg =
				tStudentArr[iStudentCount].iTotal / 3.f;
			tStudentArr[iStudentCount].iNumber = iStdNumber;

			++iStdNumber;
			++iStudentCount;

			cout << "�л� �߰� �Ϸ�" << endl;
			break;
		case MENU_DELETE:
			system("cls");
			cout << "#################### �л����� ###################" << endl;

			cin.ignore(1024, '\n');
			cout << "������ �̸� �Է� : ";
			cin.getline(strName, NAME_SIZE);

			// ��ϵǾ� �ִ� �л� ����ŭ �ݺ��Ͽ� �л� ã��
			for (int i = 0; i < iStudentCount; i++) {
				// �л� ã�Ҵٸ�
				if (strcmp(tStudentArr[i].strName, strName) == 0) {
					for (int j = 0; j < iStudentCount - 1; j++) {
						tStudentArr[i] = tStudentArr[i + 1];
					}
					--iStudentCount;

					cout << "�л� ������" << endl;
					break;
				}
			}
			break;
		case MENU_SEARCH:
			system("cls");
			cout << "#################### �л�Ž�� ###################" << endl;
			
			cin.ignore(1024, '\n');
			cout << "Ž���� �̸� �Է� : ";
			cin.getline(strName, NAME_SIZE);

			// ��ϵǾ� �ִ� �л� ����ŭ �ݺ��Ͽ� �л� ã��
			for (int i = 0; i < iStudentCount; i++) {
				if (strcmp(tStudentArr[i].strName, strName) == 0) {
					cout << "�̸� : " << tStudentArr[i].strName << endl;
					cout << "��ȭ��ȣ : " << tStudentArr[i].strPhoneNumber << endl;
					cout << "�ּ� : " << tStudentArr[i].strAddress << endl;
					cout << "�й� : " << tStudentArr[i].iNumber << endl;
					cout << "���� : " << tStudentArr[i].iKor << endl;
					cout << "���� : " << tStudentArr[i].iEng << endl;
					cout << "���� : " << tStudentArr[i].iMath << endl;
					cout << "���� : " << tStudentArr[i].iTotal << endl;
					cout << "��� : " << tStudentArr[i].fAvg << endl;
				}
				break;
			}
		case MENU_OUTPUT:
			system("cls");
			cout << "#################### �л���� ###################" << endl;
			// ��ϵ� �л� ����ŭ �ݺ��ϸ� ���
			for (int i = 0; i < iStudentCount; i++) {
				cout << "�̸� : " << tStudentArr[i].strName << endl;
				cout << "��ȭ��ȣ : " << tStudentArr[i].strPhoneNumber << endl;
				cout << "�ּ� : " << tStudentArr[i].strAddress << endl;
				cout << "�й� : " << tStudentArr[i].iNumber << endl;
				cout << "���� : " << tStudentArr[i].iKor << endl;
				cout << "���� : " << tStudentArr[i].iEng << endl;
				cout << "���� : " << tStudentArr[i].iMath << endl;
				cout << "���� : " << tStudentArr[i].iTotal << endl;
				cout << "��� : " << tStudentArr[i].fAvg << endl;
			}
			break;
		default:
			cout << "�޴��� �߸� �����߽��ϴ�." << endl;
		}
		system("pause");
	}
	return 0;;
}