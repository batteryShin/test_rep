#include <iostream>

using namespace std;

// 템플릿 메타 프로그래밍 : 전문화 기술을 사용해서 재귀 형태로 컴파일 시간에 연산을 수행.
template<int N> struct Factorial {
	enum { value = N * Factorial<N-1>::value };
};

template<> struct Factorial<1> {
	enum { value = 1 };
};

int main() {
	int n2 = binary<101>::value;
	cout << n2 << endl; // 5가 나와야 합니다. binary를 어떻게 만들지 생각...


	int n = Factorial<5>::value;
			// 5 * F<4>::value
			// 5 * 4 * F<3>::value
			// 5 * 4 * 3 * F<2>::value
			// 5 * 4 * 3 * 2 * F<1>::value
			// 5 * 4 * 3 * 2 * 1

	cout << n << endl;
}