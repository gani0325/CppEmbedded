/* struct 구조체이름 {
        자료형 멤버변수이름;
        ...
}; */
struct Student
{
    int number;
    char name[10];
    double height;
};

struct Student
{
    // 상수 정의
    enum
    {
        NAME_LEN = 10,
        SHOW = 5
    };

    int number;
    char name[NAME_LEN];
    double height;
    void ShowStudentInform() { ... }
};

class Student
{
private:
    int number;
    char name[NAME_LEN];

public:
    double height;
    void ShowStudentInform() { ... }
};

/*
클래스는 별도로 접근제어 지시자를 명시하지 않으면, 모든 변수와 함수는 private로 선언된다.
구조체는 별도로 접근제어 지시자를 명시하지 않으면, 모든 변수와 함수는 public으로 선언된다
*/