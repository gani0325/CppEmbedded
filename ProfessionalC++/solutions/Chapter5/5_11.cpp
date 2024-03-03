// 깊은 복사 생성자를 가진 정상적인 Person 클래스
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

// 깊은 복사 생성자 작성
Person::Person(const Person &person)
{
    this->id = person.id;
    int len = strlen(person.name);
    this->name = new char[len + 1];
    strcpy(this->name, person.name);
    cout << "복사 생성자 실행. 원본 객체의 이름" << this->name << endl;
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
    // Person 에 작성된 깊은 복사 생성자 호출
    Person daughter(father);

    cout << "daughter 객체 생성 직후 ---" << endl;
    father.show();
    daughter.show();

    daughter.changeName("tani");
    cout << "daugther 이름을 tani 로 변경한 후 ---" << endl;
    father.show();
    daughter.show();

    // daughter, father 순으로 소멸
    return 0;
}

/*
복사 생성자 실행. 원본 객체의 이름gani
daughter 객체 생성 직후 ---
1, gani
1, gani
daugther 이름을 tani 로 변경한 후 ---
1, gani
1, tani
*/