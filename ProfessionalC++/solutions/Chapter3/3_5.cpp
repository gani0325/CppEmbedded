// 멤버 변수 초기화와 위임 생성자 활용
#include <iostream>
using namespace std;

class Point
{
    int x, y;

public:
    Point();
    Point(int a, int b);
    void show()
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

// 위임 생성자
Point::Point() : Point(0, 0) {}

// 타겟 생성자
Point::Point(int a, int b) : x(a), y(b) {}

int main()
{
    Point origin;
    Point target(10, 20);

    origin.show();
    target.show();
}

/*
(0, 0)
(10, 20)
*/

/*
생성자와 멤버 변수의 초기화
클래스의 멤버 변수들은 자동으로 초기화되지 않기 때문에 생성자에서 초기화한다
1) 생성자 코드에서 멤버 변수 초기화
Point::Point()
{
    x = 0;
    y = 0;
}
Point::Point(int a, int b)
{
    x = a;
    y = b;
}

2) 생성자 서두에 초깃값으로 초기화
Point::Point() : x(0), y(0)
{
}
Point::Point(int a, int b)
{
    : x(a), y(b)
}

3) 클래스 선언부에서 직접 초기ㅗ하
class Point
{
    int x = 0;
    int y = 0;
};
*/