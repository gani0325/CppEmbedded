#include <iostream>
using namespace std;

#define NAME_SIZE	64
/*
구조체 : 관련있는 변수들을 모아서 하나의 새로운 타입을 만들어주는 기능
사용자 정의 변수 타입
struct 구조체명 {};

배열과 구조체의 공통점 :
1. 데이터 집합
2. 연속된 메모리 블럭에 할당됨
구조체 멤버들은 연속된 메모리 블럭으로 잡힘

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

	// 구조체 멤버에 접근할 때 .이용해서 접근
	tStudent.iKor = 100;

	// strcpy_s 함수 이용해서 문자열 복사하기
	// 오른쪽에 있는 문자열을 왼쪽으로 복사
	// 문자열의 끝은 항상 0(null)로 끝나야 한다
	// 각 배열요소에 값 넣어주면 그 값 출력
	// 넣어주지 않은 값 부분은 쓰레기값 출력
	// strcpy_s 는 자동으로 끝에 항상 0(null) 넣어줌
	strcpy_s(tStudent.strName, "가나다라 abcd");

	// strcat_s 함수는 문자열을 붙여주는 기능
	strcat_s(tStudent.strName, "문자열 붙이기");

	// strcmp 함수는 두 문자열을 비교하여 같은 경우 0 반환
	// 다를 경우 0이 아닌 값 반환
	strcmp(tStudent.strName, "홍길동");

	// strlen 함수는 문자열 길이
	strlen(tStudent.strName);

	cout << "비교할 이름 : ";
	char strName[NAME_SIZE] = {};
	cin >> strName;

	strcpy_s(tStudent.strName, "가니");

	if (strcmp(tStudent.strName, strName) == 0) {
		cout << "학생 찾음" << endl;
	}
	else {
		cout << "학생 없음" << endl;
	}

	cout << "이름 : " << tStudent.strName << endl;
	cout << "학번 : " << tStudent.iNumber << endl;
	cout << "국어 : " << tStudent.iKor << endl;
	cout << "영어 : " << tStudent.iEng << endl;
	cout << "수학 : " << tStudent.iMath << endl;
	cout << "총점 : " << tStudent.iTotal << endl;
	cout << "평균 : " << tStudent.fAvg << endl;
	return 0;;
}