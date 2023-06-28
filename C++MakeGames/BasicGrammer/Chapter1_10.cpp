// Chapter1_10

#include <iostream>
using namespace std;

int main()
{
	/*
	배열
	변수타입 배열명[개수];
	: 여러 개의 변수를 한번에 생성해줄 수 있는 기능
	: 배열은 연속된 메모리 블럭에 공간이 할당됨
	: 인덱스를 이용해서 원하는 부분에 접근하여 값 저장함
	: 인덱스는 0부터 n-1
	: 선언하고 값을 초기화하지 않을 경우 쓰레기 값이 들어감!
	*/

	// 중괄호를 대입할 경우 모든 인덱스를 0으로 초기화
	int iArrary[10] = {};
	iArrary[1] = 1234;

	cout << iArrary[5] << endl;

	return 0;
}