#include <iostream>

using namespace std;

/*
	다중 상속
	- 1. Diamond 상속의 문제점
		Diamond 상속이 발생할때는 1차 자식에서 가상상속을 해야한다

*/


class X { public: int x; };
class A : virtual public X { public: int a; };
class B : public virtual X { public: int b; };

class C : public A, public B {};

int main() {
	C c;
	c.x = 10;
}