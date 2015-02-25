#include <iostream>

using namespace std;

class A {
	int a;
public:
	void foo() { cout << "A foo" << endl; }
};

class B {
	int b;
public:
	virtual void goo() { cout << "B goo" << endl; }
};

int main() {
	A aaa;
	B* p = reinterpret_cast<B*>( &aaa );
	p->goo();			// *p[0](p)
}