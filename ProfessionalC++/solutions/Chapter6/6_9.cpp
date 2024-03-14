// 디폹트트 매개 변수로 인한 함수 중복의 모호성
#include <iostream>
#include <string>
using namespace std;

void msg(int id)
{
    cout << id << endl;
}

void msg(int id, string s = "")
{
    cout << id << ":" << s << endl;
}

int main()
{
    msg(5, "Good morning");
    // 함수 호출 모호. 컴파일 오류
    msg(6);
}

/*
/home/gani/CppEmbedded/ProfessionalC++/solutions/Chapter6/6_9.cpp:20:10: error: call of overloaded ‘msg(int)’ is ambiguous
   20 |     msg(6);
      |          ^
/home/gani/CppEmbedded/ProfessionalC++/solutions/Chapter6/6_9.cpp:6:6: note: candidate: ‘void msg(int)’
    6 | void msg(int id)
      |      ^~~
/home/gani/CppEmbedded/ProfessionalC++/solutions/Chapter6/6_9.cpp:11:6: note: candidate: ‘void msg(int, std::string)’
   11 | void msg(int id, string s = "")
*/