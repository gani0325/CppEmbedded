#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

#define BUF_SIZE 100
#define MAX_CLNT 256

void *handle_clnt(void *arg);
void send_msg(char *msg, int len);
void error_handling(char *message);

int clnt_cnt = 0;         // 서버에 접속한 클라이언트 수
int clnt_socks[MAX_CLNT]; // 클라이언트와의 송수신을 위해 생성한 소켓의 파일 디스크립터를 저장한 배열
pthread_mutex_t mutx;     // 뮤텍스를 통한 쓰레드 동기화를 위한 변수

int main(int argc, char *argv[])
{
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_adr, clnt_adr;
    socklen_t clnt_adr_sz;
    pthread_t t_id;

    if (argc != 2) // 실행파일 경로/PORT번호 를 입력으로 받아야 함
    {
        printf("Usage : %s <port> \n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pthread_mutex_init(&mutx, NULL); // 뮤텍스 생성

    serv_sock = socket(PF_INET, SOCK_STREAM, 0); // TCP 소켓 생성

    /* 서버 주소정보 초기화 */
    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr.sin_port = htons(atoi(argv[1]));

    /* 서버 주소정보를 기반으로 주소할당 */
    bind(serv_sock, (struct sockaddr *)&serv_adr, sizeof(serv_adr));

    /* 서버소켓(리스닝소켓)이 됨
    연결요청 대기큐를 생성하고, 클라이언트의 연결요청을 기다림
    */
    listen(serv_sock, 5);

    while (true)
    {
        clnt_adr_sz = sizeof(clnt_adr);

        /* 클라이언트의 연결요청을 수락하고,
        클라이언트와의 송수신을 위한 새로운 소켓 생성 */
        clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_adr, &clnt_adr_sz);
        printf("Connected client IP: %s \n", inet_ntoa(clnt_adr.sin_addr));
        // 클라이언트의 IP정보를 문자열로 변환하여 출력

        pthread_mutex_lock(&mutx);          // 뮤텍스 lock
        clnt_socks[clnt_cnt++] = clnt_sock; // 클라이언트 수와 파일 디스크립터를 등록
        pthread_mutex_unlock(&mutx);        // 뮤텍스 unlock

        pthread_create(&t_id, NULL, handle_clnt, (void *)&clnt_sock); // 쓰레드 생성 및 실행
        pthread_detach(t_id);                                         // 쓰레드가 종료되면 소멸시킴
    }

    return 0;
}

void *handle_clnt(void *arg)
{
    int clnt_sock = *((int *)arg); // 클라이언트와의 연결을 위해 생성된 소켓의 파일 디스크립터
    int str_len = 0, i;
    char msg[BUF_SIZE];

    while ((str_len = read(clnt_sock, msg, sizeof(msg))) != 0) // 클라이언트로부터 EOF를 수신 할때까지 읽어서
        send_msg(msg, str_len);                                // send_msg 함수 호출

    pthread_mutex_lock(&mutx);     // 뮤텍스 lock
    for (i = 0; i < clnt_cnt; ++i) // remove disconnected client
    {
        if (clnt_sock == clnt_socks[i]) // 현재 해당하는 파일 디스크립터를 찾으면
        {
            while (i < clnt_cnt - 1) // 클라이언트가 연결요청을 했으므로 해당정보를 덮어씌워 삭제
            {
                clnt_socks[i] = clnt_socks[i + 1];
                ++i;
            }
            break;
        }
    }
    --clnt_cnt;                  // 클라이언트 수 감소
    pthread_mutex_unlock(&mutx); // 뮤텍스 unlock
    close(clnt_sock);            // 클라이언트와의 송수신을 위한 생성했던 소켓종료
    return NULL;
}

void send_msg(char *msg, int len) // send to all
{
    int i;
    pthread_mutex_lock(&mutx);     // 뮤텍스 lock
    for (i = 0; i < clnt_cnt; ++i) // 현재 연결된 모든 클라이언트에게 메세지를 전송
        write(clnt_socks[i], msg, len);
    pthread_mutex_unlock(&mutx); // 뮤텍스 unlock
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(EXIT_FAILURE); // -1
}