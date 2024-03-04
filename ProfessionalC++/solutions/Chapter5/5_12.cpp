// 묵시적 복사 생성에 의해 복사 생성자가 자동 호출되는 경우
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Person
{
    char *name;
    int id;

public:
    // 생성자
    Person(int id, const char *name);
    // 복사 생성자
    Person(const Person &person);

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

// 값에 의한 호출로 객체가 전달될 때, person 객체의 복사 생성자 호출
void f(Person person)
{
    person.changeName("dummy");
}

Person g()
{
    Person mother(2, "qani");
    // 함수에서 객체를 리턴할 때, mother 객체의 복사본 생성. 복사본의 복사 생성자 호출
    return mother;
}
int main()
{
    Person father(1, "gani");
    // 객체로 초기화하여 객체가 생성될 때, son 객체의 복사 생성자 호출
    Person son = father;
    f(father);
    g();
}

/*

*/