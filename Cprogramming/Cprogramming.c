// 사용자로부터 입력받은 크기만큼의 메모리를 동적으로 할당받은 후
// 다시 문자열을 입력받아 앞서 동적으로 할당받은 메모리에 저장하고 출력
#include <stdio.h>
#include <malloc.h>

void main(void)
{
	// 한글 이름 두 개를 입력받은 후, 같은 성인지 비교하여 같은 성이면 '같음', 
	// 그렇지 않으면 '다름'이라는 문자열을 출력하는 프로그램을 작성하세요.
	// 단, 만일 사용자가 문자열을 입력하지 않았다면 무조건 '다름'이라고 출력합니다

	char name1[10];
	char name2[10];

	//scanf_s("%c %c", name1, name2);
	gets(name1);
	gets(name2);

	puts(name1);
	puts(name2);

	if (name1[0] == name2[0] && name1[1] == name2[1]) {
		if (name1[0] == name2[0] && name2[0] == '\0' && name1[0] == '\0') {
			printf("다름");
		}
		else {
			printf("같음");
		}
	}
	else {
		printf("다름");
	}
}

/*
이가은
이다은
이가은
이다은
같음
*/