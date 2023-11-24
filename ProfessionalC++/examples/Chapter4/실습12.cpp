#include <iostream>
#include <string>
using namespace std;

class Circle {
    int radius;     // 원의 반지름 값
    string name;    // 원의 이름
public:
    void setCircle(string name, int radius);    // 이름과 반지름 설정
    double getArea();
    string getName();
};

class CircleManager {
    Circle *p;      // Circle 배열에 대한 포인터
    int size;       // 배열의 크기
public:
    CircleManager(int size);    // size 크기의 배열을 동적 생성. 사용자로부터 입력 완료
    ~CircleManager();           
    void searchByName();        // 사용자로부터 원의 이름을 입력받아 면적 출력
    void searchByArea();        // 사용자로부터 면적을 입력받아 면적보다 큰 원의 이름 출력
};

int main() {
    cout << "원의 개수 >> ";
    
    int cnt = 0;
    cin >> cnt;

    
    for (int i = 0; i < cnt; i++) {
        cout << "원 " << i+1 << "의 이름과 반지름 >> ";

        string t_name;
        cin >> t_name;
        cout << " ";

        int t_radius;
        cin >> t_radius;
        cout << endl;

        Circle circle();
        circle.setCircle(t_name, t_radius);
    }
}