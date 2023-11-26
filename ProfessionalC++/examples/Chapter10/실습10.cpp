#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>

using namespace std;

// 나라 이름과 수도 문자열로 구성됨
class Nation
{

public:
    string nation;
    string capital;
    Nation() {}
    Nation(string nation, string capital)
    {
        this->nation = nation;
        this->capital = capital;
    }
};

int main()
{
    vector<Nation> v;

    v.push_back(Nation("미국", "워싱턴"));
    v.push_back(Nation("독일", "베를린"));
    v.push_back(Nation("포르투갈", "리스본"));
    v.push_back(Nation("이탈리아", "로마"));
    v.push_back(Nation("대한민국", "서울"));

    while (1)
    {
        cout << "***** 나라의 수도 맞추기 게임을 시작합니다. *****" << endl;
        cout << "정보 입력: 1, 퀴즈: 2, 종료: 3 >> ";

        int info;
        cin >> info;

        string nation;
        string capital;

        if (info == 1)
        {
            int n = v.size();
            cout << "현재 " << n << "개의 나라가 입력되어 있습니다." << endl;
            cout << "나라와 수도를 입력하세요(no no 이면 입력끝)" << endl;

            while (1)
            {
                cout << n << ">>";
                cin >> nation >> capital;

                if ((nation == "no") && (capital == "no"))
                {
                    break;
                }

                vector<Nation>::iterator it;
                int flag = 0;
                // it = find(v.begin(), v.end(), nation);

                for (it = v.begin(); it < v.end(); it++)
                {
                    // if ((it->nation) == nation)
                    if ((it->nation) == nation)
                    {
                        cout << "already exists !!" << endl;
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    v.push_back(Nation(nation, capital));
                    n++;
                    int n = v.size();
                }
            }
        }

        else if (info == 2)
        {
            while (1)
            {
                random_device rd;                                    // 시드 넘버 생성. time처럼 시드 넘버 계속 바뀌게 한다
                mt19937 mersenne(rd());                              // 랜덤 넘버 생성 알고리즘. mersenne는 알고리즘 이름
                uniform_int_distribution<int> dist(0, v.size() - 1); // n~m 사이의 수를 랜덤하게 만든다. 단, 각 숫자가 나올 확률은 전부 동일

                auto randNum = dist(mersenne); // 균등하게 랜덤 넘버 생성
                vector<Nation>::iterator it = v.begin();

                cout << (it[randNum]).nation << "의 수도는?";

                string answer;
                cin >> answer;

                if ((it[randNum]).capital == answer)
                {
                    cout << "Correct !!" << endl;
                }
                else if (answer == "exit")
                {
                    break;
                }
                else
                {
                    cout << "NO !!" << endl;
                }
            }
        }

        else if (info == 3)
        {
            break;
        }
    }
}