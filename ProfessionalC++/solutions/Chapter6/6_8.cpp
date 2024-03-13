// 참조 매개 변수로 인한 함수 중복의 모호성
#include <iostream>
using namespace std;

int add(int a, int b)
{
    return a * b;
}

int add(int a, int &b)
{
    b = b + a;
    return b;
}

int main()
{
    int s = 10, t = 20;
    // 컴파일 오류
    // 참조 매개 변수로 인해 함수 호출이 모호함
    cout << add(s, t);
}

/*
/home/gani/CppEmbedded/ProfessionalC++/solutions/Chapter6/6_8.cpp:21:21: error: call of overloaded ‘add(int&, int&)’ is ambiguous
   21 |     cout << add(s, t);
      |                     ^
/home/gani/CppEmbedded/ProfessionalC++/solutions/Chapter6/6_8.cpp:5:5: note: candidate: ‘int add(int, int)’
    5 | int add(int a, int b)
      |     ^~~
/home/gani/CppEmbedded/ProfessionalC++/solutions/Chapter6/6_8.cpp:10:5: note: candidate: ‘int add(int, int&)’
   10 | int add(int a, int &b)
      |     ^~~
*/