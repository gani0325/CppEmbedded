#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/ioctl.h>

#define BUFFER_SIZE 4096

static char ringbuffer[BUFFER_SIZE];
static int read_ptr = 0;
static int write_ptr = 0;

// 순환 큐에 데이터를 enqueue 하는 함수
int enqueue(const char *data, size_t size)
{
    int bytes = 0;
    while (size > 0)
    {
        if ((write_ptr + 1) % BUFFER_SIZE == read_ptr)
        {
            // 순환 큐가 가득 찼을 때
            return bytes;
        }
        ringbuffer[write_ptr] = *data;
        write_ptr = (write_ptr + 1) % BUFFER_SIZE;
        data++;
        size--;
        bytes++;
    }
    return bytes;
}

// 순환 큐에서 데이터를 dequeue 하여 버퍼에 저장
int dequeue(char *buffer, size_t size)
{
    int bytes_read = 0;
    while (size > 0)
    {
        if (read_ptr == write_ptr)
        {
            // 순환 큐가 완전히 비었을 때
            return bytes_read;
        }
        *buffer = ringbuffer[read_ptr];
        read_ptr = (read_ptr + 1) % BUFFER_SIZE;
        buffer++;
        size--;
        bytes_read++;
    }
    return bytes_read;
}

int main()
{
    int fd = open("/dev/ringbuffer", O_RDWR); // 디바이스 파일 열기
    if (fd == -1)
    {
        perror("Failed to open the device file");
        return 1;
    }

    const char *data = "";
    char buffer[20];

    // 데이터를 enqueue
    int bytes = enqueue(data, strlen(data));
    printf("Enqueued %d bytes\n", bytes);

    // 데이터를 dequeue
    int bytes_read = dequeue(buffer, sizeof(buffer));
    buffer[bytes_read] = '\0'; // 문자열의 끝을 나타내는 NULL 문자 추가
    printf("Dequeued %d bytes: %s\n", bytes_read, buffer);

    close(fd); // 파일 닫기
    return 0;
}
