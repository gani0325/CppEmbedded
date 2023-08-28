#include <stdio.h>
#include <string.h>

void main(void)
{
	// 사용자가 입력한 문자열에서 단어의 개수를 알아내는 프로그램을 작성하세요.
	// 단, 단어와 단어 사이에는 빈칸이나 키가 있을 수 있으며, 
	// 빈칸이나 키가 연속되면 개수와 상관없이 하나로 간주합니다.
	// 즉, 빈칸이 셋이라 해도 그중 한 개만 인정하고 나머지 둘은 무시합니다.
	// 따라서 "A B"와 같은 형식의 문자열이 있다면 단어의 개수는 2입니다.
	// 그리고 개행 문자는 문자열의 끝으로 간주하여 더는 세지(Count) 않습니다

	int cnt = 0;
	char ch;

	while (1) {
		ch = getchar();

		if (ch == NULL || ch == 0 || ch == ' ') {
			continue;
		}
		else if (ch == '\n') {
			printf("단어의 개수는 %d개", cnt);
		}
		else {
			cnt += 1;
		}
	}
}

/*
a b c d e
단어의 개수는 5개
*/