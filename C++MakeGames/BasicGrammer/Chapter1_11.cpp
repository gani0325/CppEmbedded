// Chapter1_10

#include <iostream>
using namespace std;

int main()
{
	// Lotto Program
	system("cls");
	srand((unsigned int)time(0));

	int iLotto[45] = {};

	// 1 ~ 45까지의 숫자를 차례대로 넣어준다
	for (int i = 0; i < 45; i++) {
		iLotto[i] = i + 1;
	}

	// Swap 알고리즘
/*	int iNum1 = 1, iNum2 = 2, iNum3;
	iNum3 = iNum1;
	iNum1 = iNum2;
	iNum2 = iNum3;*/

	// shuffle
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; i++) {
		idx1 = rand() % 45;
		idx2 = rand() % 45;

		iTemp = iLotto[idx1];
		iLotto[idx1] = iLotto[idx2];
		iLotto[idx2] = iTemp;
	} 
	for (int i = 0; i < 45; i++) {
		cout << iLotto[i] << endl;
	}
	return 0;
}