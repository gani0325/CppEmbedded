// Chapter1_5

#include <iostream>
using namespace std;

int main()
{
	// ��� : ������ �ʴ� ��. �ѹ� �����ϸ� �ٲ� �� ����
	// ����� ����� ���ÿ� �� �����ؾ� ��
	const int	iAttack = 0x00000001;	// 1
	const int	iArmor = 0x00000002;	// 10
	const int	iHP = 0x00000004;		// 100
	const int	iMP = 0x00000008;		// 1000
	const int	iCritical = 0x00000010;	// 10000

	// 1 | 100 => 101 | 10000 => 10101
	int iBuf = iAttack | iHP | iCritical;

	// ������ ����� : ������ �ٿ��� ��� ����
	// iBuf = iBuf ^ iHP;	(�ٸ� ���� ��)
	// 10101 ^ 00100 = 10001

	// 10101 & 00001 = 1
	cout << "Attack : " << (iBuf & iAttack) << endl;
	// 10101 & 00010 = 0
	cout << "Armor : " << (iBuf & iArmor) << endl;

	/*
	����Ʈ ������ : <<, >> �� �� �� �����Ͽ� ������ ����
	������ ������ ������
	20 << 2 => 10100 << 2 ���������� 0 ��ĭ ���̱� => 1010000 => 64 + 16 = 80
	20 << 3 => 10100000 => 160
	��, 2^n ���ϱ�

	20 >> 2 => 101 = 5
	20 >> 3 => 10 = 2
	��, 2^n ������ (�Ҽ��� ��)
	*/

	int iHigh = 187;
	int iLow = 13560;
	int iNumber = iHigh;

	// iNumber ���� 187 ��
	// < �������� 16��Ʈ �̵���Ű�� ���� 16��Ʈ�� ���� ��
	iNumber <<= 16;

	// ���� 16��Ʈ ä���
	iNumber |= iLow;

	// iHigh ����ϱ�
	cout << "High : " << (iNumber >> 16) << endl;
	cout << "Low : " << (iNumber & 0x0000ffff) << endl;

	// ���� ������ : ++, --

	// ��ġ
	++iNumber;

	// ��ġ
	iNumber++;

	cout << ++iNumber << endl;
	cout << iNumber++ << endl;
	return 0;
}
