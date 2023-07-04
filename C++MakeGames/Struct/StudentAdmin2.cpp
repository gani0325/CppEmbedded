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

	// 배열에 추가된 개수를 저장할 변수 만들기
	int iStudentCount = 0;
	int iStdNumber = 0;

	char strName[NAME_SIZE] = {};

	while (true) {
		system("cls");

		// 메뉴 출력
		cout << "1. 학생등록" << endl;
		cout << "2. 학생삭제" << endl;
		cout << "3. 학생탐색" << endl;
		cout << "4. 학생출력" << endl;
		cout << "5. 종료" << endl;
		cout << "메뉴를 선택하세요 : ";
		int iMenu;
		cin >> iMenu;

		//버퍼 : 임시저장공간
		//cin 내부에 입력버퍼가 있는데 입력버퍼는 입력한 값을 저장하고
		//그 값을 변수에 넣어주는 역할
		//에러 체크하고, cin.fail() 했을 때 입력 에러가 발생하면 true 반환
		if (cin.fail()) {
			// 에러버퍼 비우기
			cin.clear();

			// 입력버퍼에 \n가 남아있으므로 입력버퍼를 검색하여 \n 지우기
			// 첫번째는 검색하고자 하는 버퍼 크기 저장 (넉넉하게 1024 byte)
			// 찾고자 하는 문자 넣기
			cin.ignore(1024, '\n');
			continue;
		}

		if (iMenu == MENU_EXIT)
			break;

		switch (iMenu) {
		case MENU_INSERT:
			system("cls");
			cout << "#################### 학생추가 ###################" << endl;
			// 최대 등록치 까지만 추가하기
			if (iStudentCount == STUDENT_MAX)
				break;
			// 학생 정보 추가
			// 이름, 주소, 전화번호
			// 국어, 영어, 수학 점수는 입력받고 학번, 총점, 평균은 연산
			// 이름 입력받기
			cout << "이름 : ";
			cin >> tStudentArr[iStudentCount].strName;

			cin.ignore(1024, '\n');
			cout << "주소 : ";
			cin.getline(tStudentArr[iStudentCount].strAddress, ADDRESS_SIZE);

			cout << "전화번호 : ";
			cin.getline(tStudentArr[iStudentCount].strPhoneNumber, PHONE_SIZE);

			cout << "국어 : ";
			cin >> tStudentArr[iStudentCount].iKor;

			cout << "영어 : ";
			cin >> tStudentArr[iStudentCount].iEng;

			cout << "수학 : ";
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

			cout << "학생 추가 완료" << endl;
			break;
		case MENU_DELETE:
			system("cls");
			cout << "#################### 학생삭제 ###################" << endl;

			cin.ignore(1024, '\n');
			cout << "삭제할 이름 입력 : ";
			cin.getline(strName, NAME_SIZE);

			// 등록되어 있는 학생 수만큼 반복하여 학생 찾기
			for (int i = 0; i < iStudentCount; i++) {
				// 학생 찾았다면
				if (strcmp(tStudentArr[i].strName, strName) == 0) {
					for (int j = 0; j < iStudentCount - 1; j++) {
						tStudentArr[i] = tStudentArr[i + 1];
					}
					--iStudentCount;

					cout << "학생 삭제함" << endl;
					break;
				}
			}
			break;
		case MENU_SEARCH:
			system("cls");
			cout << "#################### 학생탐색 ###################" << endl;
			
			cin.ignore(1024, '\n');
			cout << "탐색할 이름 입력 : ";
			cin.getline(strName, NAME_SIZE);

			// 등록되어 있는 학생 수만큼 반복하여 학생 찾기
			for (int i = 0; i < iStudentCount; i++) {
				if (strcmp(tStudentArr[i].strName, strName) == 0) {
					cout << "이름 : " << tStudentArr[i].strName << endl;
					cout << "전화번호 : " << tStudentArr[i].strPhoneNumber << endl;
					cout << "주소 : " << tStudentArr[i].strAddress << endl;
					cout << "학번 : " << tStudentArr[i].iNumber << endl;
					cout << "국어 : " << tStudentArr[i].iKor << endl;
					cout << "영어 : " << tStudentArr[i].iEng << endl;
					cout << "수학 : " << tStudentArr[i].iMath << endl;
					cout << "총점 : " << tStudentArr[i].iTotal << endl;
					cout << "평균 : " << tStudentArr[i].fAvg << endl;
				}
				break;
			}
		case MENU_OUTPUT:
			system("cls");
			cout << "#################### 학생출력 ###################" << endl;
			// 등록된 학생 수만큼 반복하며 출력
			for (int i = 0; i < iStudentCount; i++) {
				cout << "이름 : " << tStudentArr[i].strName << endl;
				cout << "전화번호 : " << tStudentArr[i].strPhoneNumber << endl;
				cout << "주소 : " << tStudentArr[i].strAddress << endl;
				cout << "학번 : " << tStudentArr[i].iNumber << endl;
				cout << "국어 : " << tStudentArr[i].iKor << endl;
				cout << "영어 : " << tStudentArr[i].iEng << endl;
				cout << "수학 : " << tStudentArr[i].iMath << endl;
				cout << "총점 : " << tStudentArr[i].iTotal << endl;
				cout << "평균 : " << tStudentArr[i].fAvg << endl;
			}
			break;
		default:
			cout << "메뉴를 잘못 선택했습니다." << endl;
		}
		system("pause");
	}
	return 0;;
}