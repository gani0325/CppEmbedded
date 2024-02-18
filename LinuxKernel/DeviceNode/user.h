#ifndef USER_H
#define USER_H

#include <stddef.h>

#define BUFFER_SIZE 4096

// 순환 큐에 데이터를 enqueue 하는 함수
int ringbuffer_enqueue(const char *data, size_t size);

// 순환 큐에서 데이터를 dequeue 하여 버퍼에 저장
int ringbuffer_dequeue(char *buffer, size_t size);

#endif /* USER_H */
