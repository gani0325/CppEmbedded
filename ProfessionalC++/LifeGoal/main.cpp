// 나의 LifeGoal 을 wsl 실행마다 상기 시키기
// shell에 export PICO 등록시키기!!
// export PICO_SDK_PATH=~/pico/pico-sdk
// vim .bashrc
// 설정 파일 맨 밑에... 프로그램 넣으면 됨
// cd (내 홈 디렉터리)
// ./main.out

#include <string>
#include <vector>
#include <iostream>

#include <vector>
#include <boost/pfr.hpp>
#include <boost/pfr/core_name.hpp>

using namespace std;

struct NextYear
{
    vector<string> Personal;
    vector<string> Career;
    vector<string> Business;
    vector<string> Economic;
    vector<string> Toy;
    vector<string> Adventure;
    vector<string> Contrubution;
};

struct TenYear
{
    vector<string> Personal;
    vector<string> Career;
    vector<string> Business;
    vector<string> Economic;
    vector<string> Toy;
    vector<string> Adventure;
    vector<string> Contrubution;
};

struct LifeGoal
{
    struct NextYear next;
    struct TenYear ten;
};

int main()
{
    struct LifeGoal goal;

    goal.next.Personal.push_back("IT 취업 준비 및 합격");
    goal.next.Career.push_back("C 기반 임베디드 교육생");
    goal.next.Business.push_back("안정적 매출 만들기");
    goal.next.Economic.push_back("청년 저축 가입");
    goal.next.Toy.push_back("애플 조이스틱 게임기 사기");
    goal.next.Adventure.push_back("전국 투어하기");
    goal.next.Contrubution.push_back("취준생들에게 멘토 되어주기");


    goal.ten.Personal.push_back("만물의 초연결을 어우르는 전문가 되기");
    goal.ten.Career.push_back("멋쟁이 상사");
    goal.ten.Business.push_back("더 넓은 분야 진출");
    goal.ten.Economic.push_back("자택 사기");
    goal.ten.Toy.push_back("증강현실 (VR) 에서 친구들 만나기");
    goal.ten.Adventure.push_back("스페인가서 가우디 건축물 보고 영감 얻기");
    goal.ten.Contrubution.push_back("해외 의료 봉사 가기");

    cout << "------------------------------LIFE GOAL------------------------------" << endl;
    // LifeGoal 출력

    constexpr auto names = boost::pfr::names_as_array<LifeGoal>();

    boost::pfr::for_each_field(
        goal.next,
        [&names](const auto &fields, std::size_t idx)
        {
            // cout << idx << endl;
            cout << names[idx] << endl;

            for (auto it = fields.begin(); it < fields.end(); ++it)
            {
                auto field = *it;
                cout << "\t" << field << endl;
            }
        });


    return 0;
}