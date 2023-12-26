#include <iostream>
#include <string>

template<typename T>
void printStructMemberNames(const T& obj) {
    // 구조체 타입에서 멤버 변수 이름을 출력하는 함수
    struct MemberPrinter {
        template<typename U>
        void operator()(const char* name, U&& member) const {
            std::cout << name << std::endl;
        }
    };

    // 구조체의 각 멤버 변수에 대해 MemberPrinter를 호출하여 이름을 출력
    std::apply(MemberPrinter{}, obj);
}

// 예제 구조체
struct MyStruct {
    int a;
    double b;
    std::string c;
};

int main() {
    MyStruct myObj;
    printStructMemberNames(myObj);

    return 0;
}
