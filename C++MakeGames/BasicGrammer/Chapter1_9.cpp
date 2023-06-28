// Chapter1_9

#include <iostream>
using namespace std;

int main()
{
	// 다이아몬드로 별 찍기
	int iLine = 7;
	int iCnt = 0;

	for (int i = 0; i < iLine; i++) {
		// 공백 : 3 2 1 0 1 2 3
		// 별 : 1 3 5 7 5 3 1
		iCnt = i;

		// i값이 4, 5, 6 일때만 들어감
		if (i > iLine / 2) {
			iCnt = iLine - 1 - i;
		}

		// i값이 0, 1, 2, 3 일때는 그대로 iCnt 대입
		// i값이 4, 5, 6 일때는 iCnt 2, 1, 0 대입
		// 즉, i는 0, 1, 2, 3, 2, 1, 0

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