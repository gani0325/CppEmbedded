// user_program.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int value_to_enqueue = 42;
    int dequeued_value;

    // Enqueue
    int enqueue_result = syscall(350, value_to_enqueue);

    if (enqueue_result == 0) {
        printf("Enqueue successful\n");
    } else {
        fprintf(stderr, "Enqueue failed\n");
        exit(EXIT_FAILURE);
    }

    // Dequeue
    dequeued_value = syscall(351);

    if (dequeued_value != -1) {
        printf("Dequeued value: %d\n", dequeued_value);
    } else {
        fprintf(stderr, "Dequeue failed or queue is empty\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}

/*
gcc user_program.c -o user_program
./user_program
*/