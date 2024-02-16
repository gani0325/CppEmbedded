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