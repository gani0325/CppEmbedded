// #include : ��� ������ ���⿡ ���Խ�Ű�� ���
#include <iostream>
using namespace std;
// ���� ���� : ������(���� �۾�) -> ���� -> ����

// �������� main �Լ�
int main() {
	// std ��� namespace -> �̸� ��ġ�°� ����
	// cout : �ܼ�â�� ���
	// endl : ���� ���
	std::cout << "hi" << std:endl;

	/*
	���� : ���ϴ� ��, ���� �ٲ� �� ����
	�뷮�� �ּҴ��� : bit
	1byte = 8bit
	1kbyte = 1024byte
	1mbyte = 1024kbyte
	1gbyte = 1024mbyte
	1tbyte = 1024gbyte

	���ڸ� ǥ���ϴ� ��� : ASCII �ڵ� 
	false : 0
	true : 0 �� �ƴ� ��� ��
	unsigned : ��ȣ�� ����

	����	|	�뷮	|	������	|	ǥ������	|	unsigned
	char		1byte		����		-128 ~ 127		0 ~ 255
	bool		1byte		��/����		true/false		true/false
	short		2byte		����		-32768 ~ 32767	0 ~ 65535
	int			4byte		����		-22�� ~ 21��	0 ~ �� 43��
	float		4byte		�Ǽ�		
	double		8byte		�Ǽ�

	= : ���Կ�����, ������ �ִ� ���� �������� ������

	�����̳� ���ڴ� 1byte ����
	�ѱ��̳� �ѹ� �� ���ڵ��� 2byte �� �����ϹǷ� char ���� �ϳ��� ���� x
	*/
	float fNumber = 3.25f;
	cout << fNumber << endl;

	double dNumber = 123.4567;
	cout << dNumber << endl;

	return 0;
}
