#include <iostream>

using namespace std;

// ���ø� ��Ÿ ���α׷��� : ����ȭ ����� ����ؼ� ��� ���·� ������ �ð��� ������ ����.
template<int N> struct Factorial {
	enum { value = N * Factorial<N-1>::value };
};

template<> struct Factorial<1> {
	enum { value = 1 };
};

int main() {
	int n2 = binary<101>::value;
	cout << n2 << endl; // 5�� ���;� �մϴ�. binary�� ��� ������ ����...


	int n = Factorial<5>::value;
			// 5 * F<4>::value
			// 5 * 4 * F<3>::value
			// 5 * 4 * 3 * F<2>::value
			// 5 * 4 * 3 * 2 * F<1>::value
			// 5 * 4 * 3 * 2 * 1

	cout << n << endl;
}