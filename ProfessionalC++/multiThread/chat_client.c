#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

#define BUF_SIZE 100
#define NAME_SIZE 20

void *send_msg(void *arg);
void *recv_msg(void *arg);
void error_handling(char *message);

char name[NAME_SIZE] = "[DEFAULT]";
char msg[BUF_SIZE];

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in serv_addr;
    pthread_t snd_thread, rcv_thread;
    void *thred_return;

    if (argc != 4) // 실행파일 경로/IP/PORT번호/채팅닉네임 을 입력으로 받아야 함
    {
        printf("Usage : %s <IP> <port> <name> \n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sprintf(name, "[%s]", argv[3]);
    sock = socket(PF_INET, SOCK_STREAM, 0); // TCP 소켓 생성

    /* 서버 주소정보 초기화 */
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    /* 서버 주소정보를 기반으로 연결요청
    이때 비로소 클라이언트 소켓이 됨 */
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    pthread_create(&snd_thread, NULL, send_msg, (void *)&sock); // 쓰레드 생성 및 실행
    pthread_create(&rcv_thread, NULL, recv_msg, (void *)&sock); // 쓰레드 생성 및 실행

    pthread_join(snd_thread, &thred_return); // 쓰레드 종료까지 대기
    pthread_join(rcv_thread, &thred_return); // 쓰레드 종료까지 대기
    close(sock);                             // 클라이언트 소켓 연결종료

    return 0;
}

void *send_msg(void *arg) // send thread main
{
    int sock = *((int *)arg); // 클라이언트의 파일 디스크립터
    char name_msg[NAME_SIZE + BUF_SIZE];
    while (true)
    {
        fgets(msg, BUF_SIZE, stdin);
        if (!strcmp(msg, "q\n") || !strcmp(msg, "Q\n"))
        {
            close(sock);        // 클라이언트 소켓 연결종료 후
            exit(EXIT_SUCCESS); // 프로그램 종료
        }
        sprintf(name_msg, "%s %s", name, msg);   // client 이름과 msg를 합침
        write(sock, name_msg, strlen(name_msg)); // 널문자 제외하고 서버로 문자열을 보냄
    }
    return NULL;
}

void *recv_msg(void *arg) // read thread main
{
    int sock = *((int *)arg); // 클라이언트의 파일 디스크립터
    char name_msg[NAME_SIZE + BUF_SIZE];
    int str_len;
    while (true)
    {
        str_len = read(sock, name_msg, NAME_SIZE + BUF_SIZE - 1);
        if (str_len == -1) // read 실패시
            return (void *)-1;
        name_msg[str_len] = '\0';
        fputs(name_msg, stdout);
    }
    return NULL;
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(EXIT_FAILURE); // -1
}
 
/*
https://novice-programmer-story.tistory.com/38
*/