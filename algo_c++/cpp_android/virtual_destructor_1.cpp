#include <iostream>

using namespace std;

// 모든 부모의 소멸자는 반드시 가상함수 이어야 한다.
class Base {
public:
	virtual ~Base() {}		// 부모의 소멸자가 가상이면 모든 자식의 소멸자도 가상.
};

class Derived : public Base {
	Derived() { cout << "Derived()" << endl; }
	~Derived() { cout << "~Derived()" << endl; }
};

int main() {
	Base* p = new Derived;
	delete p;			// ~Derived()가 불리지 않아 bug...
}