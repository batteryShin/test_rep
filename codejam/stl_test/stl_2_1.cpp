#include <cstdlib>
#include <cstdio>
#include <iostream>

#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <limits>
#include <math.h>

#include <assert.h>
#include <unistd.h>

using namespace std;

template <typename T, int VAL>
T AddValue(T const& curvalue) {
    return (curvalue + VAL);
}

const int EVENT_ADD_HP_VALUE  = 50;    // 이벤트에 의해 추가 될 HP 값
const int EVENT_ADD_EXP_VALUE  = 30;    // 이벤트에 의해 추가 될 경험치
const int EVENT_ADD_MONEY_VALUE  = 10000;    // 이벤트에 의해 추가 될 돈

int main()
{
    int Char_HP = 250;
    cout << Char_HP <<"에서 이벤트에 의해" << AddValue<int,
         EVENT_ADD_HP_VALUE>(Char_HP) << " 로 변경" <<endl;

    float Char_EXP = 378.89f;
    cout << Char_EXP <<"에서 이벤트에 의해" << AddValue<float,
         EVENT_ADD_EXP_VALUE>(Char_EXP) << " 로 변경" <<endl;

    long long int Char_MONEY = 34567890;
    cout << Char_MONEY <<"에서 이벤트에 의해" << AddValue<long long int,
         EVENT_ADD_MONEY_VALUE>(Char_MONEY) << " 로 변경" <<endl;
}

#if 0
template <typename T1, typename T2> 
const T1& Max(const T1& a, const T2& b) {
    cout << "Max(const T& a, const T& b) 템플릿 버전 사용" << endl;
    return (a>b) ? a : b;
}

template <>
const double& Max(const double& a, const double& b) {
    cout << "Max(const double& a, const double& b) 전문화 버전 사용" << endl;
    return (a>b) ? a : b;
}

int main()
{
    double Char1_MP = 300;
    double Char1_SP = 400.25;
    double MaxValue1 = Max( Char1_MP, Char1_SP );
    cout << "MP와 SP 중 가장 큰 값은" << MaxValue1 << "입니다." << endl << endl;

    int Char2_MP = 300;
    double Char2_SP = 400.25; 
    double MaxValue2 = Max( Char2_MP, Char2_SP );
    cout << "MP와 SP 중 가장 큰 값은" << MaxValue2 << "입니다." << endl << endl;
}
#endif
