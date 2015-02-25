#include <iostream>

using namespace std;

template<typename T> class stack {
	T buff[10];

public:
	stack() {}		// ok
//	stack<T>() {}	// error

//	stack(const stack& s) {}		// �Ʒ��� �´� ǥ���̳�, Ŭ���� ���� ���ο����� ���.
	stack(const stack<T>& s) {}		// ok.

	// ��� �Լ�
	void push(T a);

	// static ��� ����
	static int count;

	// Ŭ���� ���ø��� ����Լ� ���ø�
	template<typename U> T foo(U a);
};

template<typename T> int stack<T>::count = 0;
template<typename T> void stack<T>::push(T a) {

}

template<typename T> template<typename U> T stack<T>::foo(U a) {
}

int main() {
	stack s1;			// error. stack�� Ÿ���� �ƴ϶� Ʋ(template) �̴�.
	stack<int> s2;		// ok. stack<int>�� Ÿ���̴�.
}