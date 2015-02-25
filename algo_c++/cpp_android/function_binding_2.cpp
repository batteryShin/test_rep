#include <iostream>

using namespace std;

class Animal {
	int age;
public:
	virtual void foo() {}
	virtual void goo() {}
};

class dog : public Animal {
	int color;
public:
	virtual void foo() {}
};

int main() {
	Animal a;
	cout << sizeof(a) << endl;
	
	Dog d;
	cout << sizeof(d) << endl;

	Animal* p = &d;
	p->foo();			// *p[0](p) 라는 기계어 코드 생성.
}