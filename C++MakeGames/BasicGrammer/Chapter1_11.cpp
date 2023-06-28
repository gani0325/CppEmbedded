// Chapter1_10

#include <iostream>
using namespace std;

int main()
{
	// Lotto Program
	system("cls");
	srand((unsigned int)time(0));

	int iLotto[45] = {};

	for (int i = 0; i < 6; i++) {
		cout << (rand() % 45 + 1) << endl;
	}
	return 0;
}