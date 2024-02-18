#include <iostream>
using namespace std;

class Rectangle
{
public:
    int width, height;
    // 생성자
    Rectangle();
    Rectangle(int w, int h);
    Rectangle(int length);
    bool isSquare();
};

Rectangle::Rectangle()
{
    width = height = 1;
}

Rectangle::Rectangle(int w, int h)
{
    width = w;
    height = h;
}

Rectangle::Rectangle(int length)
{
    width = height = length;
}

bool Rectangle::isSquare()
{
    if (width == height)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Rectangle rect1;
    Rectangle rect2(3, 5);
    Rectangle rect3(3);

    if (rect1.isSquare())
        cout << "rect1 은 정사각형!" << endl;
    if (rect2.isSquare())
        cout << "rect2 은 정사각형!" << endl;
    if (rect3.isSquare())
        cout << "rect3 은 정사각형!" << endl;
}

/*
rect1 은 정사각형!
rect3 은 정사각형!

클래스에 생성자가 꼭 있어야 할까?
- 기본 생성자 = 디폴트 생성자
클래스에 선언된 어떤 생성자도 없을 때 컴파일러가 자동으로 생성해주는 생성자
매개변수가 없는 생성자
생성자가 하나도 없는 클래스의 경우 컴파잉ㄹ러는 보이지 않게 기본 생성자를 삽입한다
생성자가 하나라도 선언된 클래스의 경우, 컴파일러는 기본 생성자를 자동 삽입하지 않는다
*/