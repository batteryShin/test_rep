#include <iostream>

using namespace std;

// primary template
template<typename T> class stack {
	T buff[10];

public:
	void push() {
		cout << "T" << endl;
	}
};

// partial specialization(�κ� ����ȭ)
template<typename T> class stack<T*> {
	T buff[10];

public:
	void push() {
		cout << "T*" << endl;
	}
};

// specialization(����ȭ)
template<> class stack<char*> {
	char* buff[10];

public:
	void push() {
		cout << "char*" << endl;
	}
};

int main() {
	stack<int> s1;
	s1.push();

	stack<int*> s2;
	s2.push();

	stack<char*> s3;
	s3.push();
}