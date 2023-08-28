#include <stdio.h>
#include <string.h>

void main(void)
{
	// 사용자로부터 입력받은 문자열에서 문자 t가 몇 개나 있는지 세어서(Count) 결과를 출력하는 프로그램을 작성하세요.
	// 단, 입력받은 문자열에 슬래시(/ )가 있으면 더 이상 세지 않고 문자열이 끝났다고 판단하며, 
	// 슬래시(/ )가 입력될 때까지 계속해서 입력을 받습니다

	int cnt = 0;
	char ch;

	while (1) {
		ch = getchar();

		if (ch == '/') {
			break;
		}
		else if (ch == 't') {
			cnt += 1;
		}
		else {
			continue;
		}
	}

	printf("t의 개수는 %d개", cnt);
}

/*

*/