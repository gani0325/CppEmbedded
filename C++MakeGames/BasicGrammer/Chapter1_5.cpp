// Chapter1_5

#include <iostream>
using namespace std;

int main()
{
	// 상수 : 변하지 않는 수. 한번 지정하면 바꿀 수 없음
	// 상수는 선언과 동시에 값 지정해야 함
	const int	iAttack = 0x00000001;	// 1
	const int	iArmor = 0x00000002;	// 10
	const int	iHP = 0x00000004;		// 100
	const int	iMP = 0x00000008;		// 1000
	const int	iCritical = 0x00000010;	// 10000

	// 1 | 100 => 101 | 10000 => 10101
	int iBuf = iAttack | iHP | iCritical;

	// 연산자 축약형 : 연산자 줄여서 사용 가능
	// iBuf = iBuf ^ iHP;	(다를 때만 참)
	// 10101 ^ 00100 = 10001

	// 10101 & 00001 = 1
	cout << "Attack : " << (iBuf & iAttack) << endl;
	// 10101 & 00010 = 0
	cout << "Armor : " << (iBuf & iArmor) << endl;

	/*
	쉬프트 연산자 : <<, >> 값 대 값 연산하여 값으로 나옴
	이진수 단위의 연산함
	20 << 2 => 10100 << 2 오른쪽으로 0 두칸 붙이기 => 1010000 => 64 + 16 = 80
	20 << 3 => 10100000 => 160
	즉, 2^n 곱하기

	20 >> 2 => 101 = 5
	20 >> 3 => 10 = 2
	즉, 2^n 나누기 (소수점 뺌)
	*/

	int iHigh = 187;
	int iLow = 13560;
	int iNumber = iHigh;

	// iNumber 에는 187 들어감
	// < 방향으로 16비트 이동시키면 상위 16비트에 값이 들어감
	iNumber <<= 16;

	// 하위 16비트 채운다
	iNumber |= iLow;

	// iHigh 출력하기
	cout << "High : " << (iNumber >> 16) << endl;
	cout << "Low : " << (iNumber & 0x0000ffff) << endl;

	// 증감 연산자 : ++, --

	// 전치
	++iNumber;

	// 후치
	iNumber++;

	cout << ++iNumber << endl;
	cout << iNumber++ << endl;
	return 0;
}
