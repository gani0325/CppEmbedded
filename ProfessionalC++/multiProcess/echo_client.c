#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
void error_handling(char *message);
void read_routine(int sock, char *buf);
void write_routine(int sock, char *buf);

int main(int argc, char *argv[])
{
    int sock;
    pid_t pid;
    char buf[BUF_SIZE];
    struct sockaddr_in serv_adr;

    if (argc != 3) // 실행파일의 경로/IP/PORT번호 를 인자로 입력받아야 함
    {
        printf("Usage : %s <IP> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sock = socket(PF_INET, SOCK_STREAM, 0); // TCP 소켓 생성
    if (sock == -1)
        error_handling("socket() error");

    /* 서버 주소정보 초기화 */
    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_adr.sin_port = htons(atoi(argv[2]));

    /* 서버 주소정보를 기반으로 클라이언트의 연결요청 */
    if (connect(sock, (struct sockaddr *)&serv_adr, sizeof(serv_adr)) == -1)
        error_handling("connect() error!");
    else
        puts("Connected................");

    pid = fork();                 // 자식 프로세스 생성
    if (pid == 0)                 // 자식 프로세스의 경우
        write_routine(sock, buf); // 출력 루틴 실행
    else                          // 부모 프로세스의 경우
        read_routine(sock, buf);  // 입력 루틴 실행

    close(sock); //
    return 0;
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(EXIT_FAILURE);
}

void read_routine(int sock, char *buf)
{
    while (true)
    {
        int str_len = read(sock, buf, BUF_SIZE - 1); // 서버로부터 데이터 수신
        if (str_len == 0)
            return;
        buf[str_len] = '\0';
        printf("Message from server: %s", buf);
    }
}

void write_routine(int sock, char *buf)
{
    while (true)
    {
        fgets(buf, BUF_SIZE, stdin); // 표준입력으로부터 입력받음

        if (!strcmp(buf, "q\n") || !strcmp(buf, "Q\n"))
        {
            shutdown(sock, SHUT_WR); // 출력 스트림 종료
            return;
        }
        write(sock, buf, strlen(buf)); // 널문자를 제외한 문자열을 서버로 송신
    }
}

/*
https://novice-programmer-story.tistory.com/22
*/