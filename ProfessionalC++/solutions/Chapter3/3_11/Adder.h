// 헤더 파일과 cpp 파일로 분리하기
// Adder.h

#ifndef ADDER_H
#define ADDER_H
class Adder
{
    int op1, op2;

public:
    Adder(int a, int b);
    int process();
};

#endif