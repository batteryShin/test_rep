#include <iostream>

// #include <stack>
/*
�̹� C++ ǥ�ؿ� top(), pop()�� �и��� ������ ����.
template ����� �����̳�(list,stack)�� ������ ��, c++������
��κ� ���ϰ� ���Ÿ� ���ÿ� �ϴ� �Լ��� ���� ����.
	1. �ӽð�ü�� ����
	2. ���� �������� ���� ������ ���ؼ�...
*/

using namespace std;

template<typename T> class stack {
	T buff[10];
	int index;

public:
	stack() : index(-1) {}

	// T�� ��ü�� �� �ִ�.
	// call by value�� ��ü�� ���, ������ ��������. ���� ������ �������.
	void push(const T& a) {
		buff[++index] = a; 
	}

	
	// pop()�� ���ſ� ������ ���ÿ� �ϸ� ���� ����ȭ �� �� ����.
	// �ӽð�ü�� ���� �� ����. �и�����.
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