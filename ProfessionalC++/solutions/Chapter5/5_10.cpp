// 얕은 복사 생성자를 사용하여 프로그램이 비정상 종료되는 경우
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Person
{
    char *name;
    int id;

public:
    // 컴파일러에 의해 디폴트 복사 생성자 자동 삽입
    Person(int id, const char *name);
    ~Person();
    void changeName(const char *name);
    void show() { cout << id << ", " << name << endl; }
};

Person::Person(int id, const char *name)
{
    this->id = id;
    int len = strlen(name);
    // name 문자열 공간 할당
    this->name = new char[len + 1];
    strcpy(this->name, name);
}

Person::~Person()
{
    // name 에 동적 할당된 배열이 있으면 동적 할당 메모리 소멸
    if (name)
        delete[] name;
}

void Person::changeName(const char *name)
{
    if (strlen(name) > strlen(this->name))
        return;
    strcpy(this->name, name);
}

int main()
{
    Person father(1, "gani");
    // 컴파일러가 삽입한 디폴트 복사 생성자 호출
    Person daughter(father);

    cout << "daughter 객체 생성 직후 ---" << endl;
    father.show();
    daughter.show();

    daughter.changeName("tani");
    cout << "daugther 이름을 tani 로 변경한 후 ---" << endl;
    father.show();
    daughter.show();

    // 비정상 종료된다
    // daughter, father 순으로 소멸.. father 가 소멸할 때 프로그램이 비정상 종료!!
    return 0;
}

/*
daughter 객체 생성 직후 ---
1, gani
1, gani
daugther 이름을 tani 로 변경한 후 ---
1, tani
1, tani
free(): double free detected in tcache 2
*/