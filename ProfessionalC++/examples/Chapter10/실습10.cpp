#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <iterator>

using namespace std;

// 나라 이름과 수도 문자열로 구성됨
class Nation
{
	string nation;
	string capital;

public:
	Nation() {}
	Nation(string nation, string capital)
	{
		this->nation = nation;
		this->capital = capital;
	}

	// NOTE (Nation const &n) -> 위에 사용하고자 하는 get_nation 에도 const 넣어야 함
	string get_nation() const
	{
		return this->nation;
	}
	string get_capital() const
	{
		return this->capital;
	}

	bool operator==(const std::string &rhs)
	{
		return this->capital == rhs;
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

				// NOTE (Nation const &n) -> 위에 사용하고자 하는 get_nation 에도 const 넣어야 함
				// auto it = find_if(v.begin(), v.end(), [&](Nation const &n ) { return n.get_nation() == nation; });

				// CHECKLIST find_if 가 아닌 find 로는 할 수 없는가?
				auto it = find(v.begin(), v.end(), nation);

				if (it == v.end())
				{
					v.push_back(Nation(nation, capital));
					n++;
					n = v.size();
				}
				else
				{
					cout << "already existed!!" << endl;
				}
			}
		}

		else if (info == 2)
		{
			while (1)
			{
				random_device rd;									 // 시드 넘버 생성. time처럼 시드 넘버 계속 바뀌게 한다
				mt19937 mersenne(rd());								 // 랜덤 넘버 생성 알고리즘. mersenne는 알고리즘 이름
				uniform_int_distribution<int> dist(0, v.size() - 1); // n~m 사이의 수를 랜덤하게 만든다. 단, 각 숫자가 나올 확률은 전부 동일

				auto randNum = dist(mersenne); // 균등하게 랜덤 넘버 생성
				vector<Nation>::iterator it = v.begin();

				cout << (it[randNum]).get_nation() << "의 수도는?";

				string answer;
				cin >> answer;

				if ((it[randNum]).get_capital() == answer)
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