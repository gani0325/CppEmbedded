// Circle 클래스의 2차원 배열 선언 및 활용
#include <iostream>
using namespace std;

class Circle
{
    int radius;

public:
    Circle() { radius = 1; }
    Circle(int r) { radius = r; }
    void setRadius(int r) { radius = r; }
    double getArea();
};

double Circle::getArea()
{
    return 3.14 * radius * radius;
}

int main()
{
    Circle circles[2][3];

    circles[0][0].setRadius(1);
    circles[0][1].setRadius(2);
    circles[0][2].setRadius(3);
    circles[1][0].setRadius(4);
    circles[1][1].setRadius(5);
    circles[1][2].setRadius(6);

    // 배열의 각 원소 객체의 멤버 접근
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "Circle [" << i << ", " << j << "] 의 면적은 ";
            cout << circles[i][j].getArea() << endl;
        }
    }
}

/*
Circle [0, 0] 의 면적은 3.14
Circle [0, 1] 의 면적은 12.56
Circle [0, 2] 의 면적은 28.26
Circle [1, 0] 의 면적은 50.24
Circle [1, 1] 의 면적은 78.5
Circle [1, 2] 의 면적은 113.04

- 다차원 객체 배열
다차원 객체 배열을 만들 수 있다
{} 안에 생성자를 지정하여 배열을 초기화할 수 있다
*/