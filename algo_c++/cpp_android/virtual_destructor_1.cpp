#include <iostream>

using namespace std;

// ��� �θ��� �Ҹ��ڴ� �ݵ�� �����Լ� �̾�� �Ѵ�.
class Base {
public:
	virtual ~Base() {}		// �θ��� �Ҹ��ڰ� �����̸� ��� �ڽ��� �Ҹ��ڵ� ����.
};

class Derived : public Base {
	Derived() { cout << "Derived()" << endl; }
	~Derived() { cout << "~Derived()" << endl; }
};

int main() {
	Base* p = new Derived;
	delete p;			// ~Derived()�� �Ҹ��� �ʾ� bug...
}