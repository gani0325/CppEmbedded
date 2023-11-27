#include <iostream>
#include <string>
using namespace std;

class Circle
{
    int radius;  // 원의 반지름 값
    string name; // 원의 이름
public:
    void setCircle(string name, int radius); // 이름과 반지름 설정
    double getArea();
    string getName();
};

void Circle::setCircle(string name, int radius)
{
    this->name = name;
    this->radius = radius;
}

double Circle::getArea()
{
    return radius * radius * 3.14;
}

string Circle::getName()
{
    return this->name;
}

class CircleManager
{
    Circle *p; // Circle 배열에 대한 포인터
    int size;  // 배열의 크기
public:
    CircleManager();
    CircleManager(int size); // size 크기의 배열을 동적 생성. 사용자로부터 입력 완료
    ~CircleManager();
    void searchByName(); // 사용자로부터 원의 이름을 입력받아 면적 출력
    void searchByArea(); // 사용자로부터 면적을 입력받아 면적보다 큰 원의 이름 출력
};

CircleManager::CircleManager() {}

CircleManager::CircleManager(int size)
{
    this->size = size;
    p = new Circle[size];
}

CircleManager::~CircleManager()
{
    delete[] p;
}

void CircleManager::searchByName()
{
    string name_;
    int radius_;

    for (int i = 0; i < size; i++)
    {
        cout << "원 " << i + 1 << "의 이름과 반지름 >> ";

        cin >> name_ >> radius_;
        p[i].setCircle(name_, radius_);
    }

    cout << "검색하고자 하는 원의 이름 >> ";
    cin >> name_;

    for (int i = 0; i < size; i++)
    {
        if (p[i].getName() == name_)
        {
            cout << name_ << "의 면적은 " << p[i].getArea() << endl;
            break;
        }
    }
}

void CircleManager::searchByArea()
{
    cout << "최소 면적을 정수로 입력하세요 >> ";

    int area_;
    cin >> area_;
    cout << area_ << "보다 큰 원을 검색합니다." << endl;

    for (int i = 0; i < size; i++)
    {
        if (p[i].getArea() > area_)
        {
            cout << p[i].getName() << "의 면적은 " << p[i].getArea() << ", ";
        }
    }
    cout << endl;
}

int main()
{
    cout << "원의 개수 >> ";

    int cnt = 0;
    cin >> cnt;

    CircleManager *p = new CircleManager(cnt);
    // CircleManager cm2;
    p->searchByName();
    p->searchByArea();

    delete p;
}