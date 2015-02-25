#include <iostream>

using namespace std;

/*
// C++ 표준은 int2type을 더욱 발전시켜서, 아래 표준을 만듦
template<typename T, T N> struct integral_constant {
	static const T value = N;		// enum 대신 static const 사용
};

integral_constant<int,0> n0;
integral_constant<short,0> s0;

// true와 false는 같은 타입의 다른 값이지만 true_type과 false_type은 다른 타입이다.
typedef integral_constant<bool,false> b0 false_type;
typedef integral_constant<bool,true> b1 true_type;

// trait_pointer는 아래처럼 제공. enum 개념을 상속으로 확장.
template<typename T> struct is_pointer : public false_type {};
template<typename T> struct is_pointer<T*> : public true_type {};
*/

#include <type_traits>

// 포인터 전용 MaxImpl
template<typename T> T MaxImpl(T a, T b, true_type) {
	cout << "포인터 전용" << endl;
	return *a<*b ? b : a;
}

// 포인터가 아닌 경우 MaxImpl
template<typename T> T MaxImpl(T a, T b, false_type) {
	cout << "포인터가 아닌경우" << endl;
	return a<b ? b : a;
}

// 사용자가 사용하는 Max
template<typename T> T Max(T a, T b) {
	return MaxImpl( a, b, is_pointer<T>() );
}

int main() {
	int x = 10, y = 20;

	Max(x,y);
	Max(&x,&y);
}