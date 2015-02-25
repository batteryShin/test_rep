#include <iostream>

using namespace std;

template<typename T> class stack {
	T buff[10];

public:
	stack() {}		// ok
//	stack<T>() {}	// error

//	stack(const stack& s) {}		// 아래가 맞는 표현이나, 클래스 선언 내부에서는 허용.
	stack(const stack<T>& s) {}		// ok.

	// 멤버 함수
	void push(T a);

	// static 멤버 변수
	static int count;

	// 클래스 템플릿의 멤버함수 템플릿
	template<typename U> T foo(U a);
};

template<typename T> int stack<T>::count = 0;
template<typename T> void stack<T>::push(T a) {

}

template<typename T> template<typename U> T stack<T>::foo(U a) {
}

int main() {
	stack s1;			// error. stack은 타입이 아니라 틀(template) 이다.
	stack<int> s2;		// ok. stack<int>는 타입이다.
}