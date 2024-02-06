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