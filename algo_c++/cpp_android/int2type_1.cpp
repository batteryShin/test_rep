#include <iostream>

using namespace std;

template<typename T> struct trait_pointer		{ enum{ value=false }; };
template<typename T> struct trait_pointer<T*>	{ enum{ value=true }; };

// Modern C++ Design å�� ���ڰ� 2000�⿡ ���� ����
template<int N> struct int2type {
	enum { value = N };
};

/*
int main() {
	foo(0);	foo(1);		// 0�� 1�� ���� Ÿ��(int)�̴�. ���� �Լ� ȣ���.

	int2type<0> t0;
	int2type<1> t1;

	foo(t0); foo(t1);	// t0�� t1�� �ٸ� Ÿ���̴�. �ٸ� �Լ� ȣ���.
}
*/

// ������ ���� MaxImpl
template<typename T> T MaxImpl(T a, T b, int2type<1>) {
	cout << "������ ����" << endl;
	return *a<*b ? b : a;
}

// �����Ͱ� �ƴ� ��� MaxImpl
template<typename T> T MaxImpl(T a, T b, int2type<0>) {
	cout << "�����Ͱ� �ƴѰ��" << endl;
	return a<b ? b : a;
}

// ����ڰ� ����ϴ� Max
template<typename T> T Max(T a, T b) {
	return MaxImpl( a, b, int2type<trait_pointer<T>::value>() );
}

/*
// if�� ����ð� �б⹮.
// ������ �ð��� ������ false�� ������ ������ �ȵ�����, �������� �ؾ���.
template<typename T> T Max(T a, T b) {
	if( trait_pointer<T>::value )
		return *a<*b ? b : a;

	return a<b ? b : a;
}
*/

int main() {
	int x = 10, y = 20;

	Max(x,y);
	Max(&x,&y);
}