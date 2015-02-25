#include <iostream>

// #include <stack>
/*
이미 C++ 표준에 top(), pop()이 분리된 스택이 있음.
template 기반의 컨테이너(list,stack)를 설계할 때, c++에서는
대부분 리턴과 제거를 동시에 하는 함수는 거의 없다.
	1. 임시객체를 막고
	2. 예외 안정성의 강력 보장을 위해서...
*/

using namespace std;

template<typename T> class stack {
	T buff[10];
	int index;

public:
	stack() : index(-1) {}

	// T는 객체일 수 있다.
	// call by value는 객체일 경우, 성능이 떨어진다. 참조 전달을 사용하자.
	void push(const T& a) {
		buff[++index] = a; 
	}

	
	// pop()이 제거와 리턴을 동시에 하면 절대 최적화 할 수 없다.
	// 임시객체를 막을 수 없다. 분리하자.
/*
	T pop() {				
		return buff[index--];
	}
*/	
	void pop() {
		--index;
	}

	T& top() {
		return buff[index];
	}
};

int main() {
	stack<int> s;
	s.push(10);
	s.push(20);
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
}