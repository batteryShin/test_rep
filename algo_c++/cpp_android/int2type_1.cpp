#include <iostream>

using namespace std;

template<typename T> struct trait_pointer		{ enum{ value=false }; };
template<typename T> struct trait_pointer<T*>	{ enum{ value=true }; };

// Modern C++ Design 책의 저자가 2000년에 만든 개념
template<int N> struct int2type {
	enum { value = N };
};

/*
int main() {
	foo(0);	foo(1);		// 0과 1은 같은 타입(int)이다. 같은 함수 호출됨.

	int2type<0> t0;
	int2type<1> t1;

	foo(t0); foo(t1);	// t0와 t1은 다른 타입이다. 다른 함수 호출됨.
}
*/

// 포인터 전용 MaxImpl
template<typename T> T MaxImpl(T a, T b, int2type<1>) {
	cout << "포인터 전용" << endl;
	return *a<*b ? b : a;
}

// 포인터가 아닌 경우 MaxImpl
template<typename T> T MaxImpl(T a, T b, int2type<0>) {
	cout << "포인터가 아닌경우" << endl;
	return a<b ? b : a;
}

// 사용자가 사용하는 Max
template<typename T> T Max(T a, T b) {
	return MaxImpl( a, b, int2type<trait_pointer<T>::value>() );
}

/*
// if는 실행시간 분기문.
// 컴파일 시간에 조건이 false가 나오면 실행은 안되지만, 컴파일은 해야함.
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