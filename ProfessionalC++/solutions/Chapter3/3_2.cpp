// Rectangle 클래스 만들기
#include <iostream>
using namespace std;

class Rectangle
{
public:
    int width;
    int height;
    int getArea();
};

// Rectangle 클래스 구현
int Rectangle::getArea()
{
    return width * height;
}

int main()
{
    // 객체 생성
    Rectangle rect;
    // 멤버 변수
    rect.width = 3;
    // 멤버 변수
    rect.height = 5;
    // 멤버 함수
    cout << "사각형의 면적은 " << rect.getArea() << endl;
}

/*
11:58:45 gani@LOVELY-GANI Chapter3 ±|master ✗|→ g++ -o 3_2 3_2.cpp
11:58:48 gani@LOVELY-GANI Chapter3 ±|master ✗|→ ./3_2
사각형의 면적은 15
*/