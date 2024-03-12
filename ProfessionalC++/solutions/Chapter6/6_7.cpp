// 형 변환으로 인해 함수 중복이 모호한 경우
#include <iostream>
using namespace std;

float square(float a)
{
    return a * a;
}

double square(double a)
{
    return a * b;
}

int main()
{
    cout << square(3.0);
    // 중복된 함수로 컴파일 오류
    cout << square(3);
}

/*
/home/gani/CppEmbedded/ProfessionalC++/solutions/Chapter6/6_7.cpp: In function ‘int main()’:
/home/gani/CppEmbedded/ProfessionalC++/solutions/Chapter6/6_7.cpp:19:21: error: call of overloaded ‘square(int)’ is ambiguous
   19 |     cout << square(3);
      |                     ^
/home/gani/CppEmbedded/ProfessionalC++/solutions/Chapter6/6_7.cpp:5:7: note: candidate: ‘float square(float)’
    5 | float square(float a)
      |       ^~~~~~
/home/gani/CppEmbedded/ProfessionalC++/solutions/Chapter6/6_7.cpp:10:8: note: candidate: ‘double square(double)’
   10 | double square(double a)
      |        ^~~~~~
*/