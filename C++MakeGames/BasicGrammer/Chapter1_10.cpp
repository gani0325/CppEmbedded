// Chapter1_10

#include <iostream>
using namespace std;

int main()
{
	/*
	do while : 반복문의 종류
	do {} while(조건식)
	while 은 처음 진입시 조건식을 체크하지만
	do while 은 처음 한번은 무조건 동작이 되고, 그 후에는 조건식을 체크해서 true 경우 동작
	*/

	int iNumber = 0;

	do {
		cout << iNumber << endl;
	} while (iNumber > 0);
	
	return 0;
}