#include <iostream>

using namespace std;

/*
// C++ ǥ���� int2type�� ���� �������Ѽ�, �Ʒ� ǥ���� ����
template<typename T, T N> struct integral_constant {
	static const T value = N;		// enum ��� static const ���
};

integral_constant<int,0> n0;
integral_constant<short,0> s0;

// true�� false�� ���� Ÿ���� �ٸ� �������� true_type�� false_type�� �ٸ� Ÿ���̴�.
typedef integral_constant<bool,false> b0 false_type;
typedef integral_constant<bool,true> b1 true_type;

// trait_pointer�� �Ʒ�ó�� ����. enum ������ ������� Ȯ��.
template<typename T> struct is_pointer : public false_type {};
template<typename T> struct is_pointer<T*> : public true_type {};
*/

#include <type_traits>

// ������ ���� MaxImpl
template<typename T> T MaxImpl(T a, T b, true_type) {
	cout << "������ ����" << endl;
	return *a<*b ? b : a;
}

// �����Ͱ� �ƴ� ��� MaxImpl
template<typename T> T MaxImpl(T a, T b, false_type) {
	cout << "�����Ͱ� �ƴѰ��" << endl;
	return a<b ? b : a;
}

// ����ڰ� ����ϴ� Max
template<typename T> T Max(T a, T b) {
	return MaxImpl( a, b, is_pointer<T>() );
}

int main() {
	int x = 10, y = 20;

	Max(x,y);
	Max(&x,&y);
}