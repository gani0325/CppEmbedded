#include "stdio.h"

int add(int, int);

int main(int argc, char **argv)
{
    int x = add(4, 5);
    printf("Result: %d\n", x);
    return 0;
}