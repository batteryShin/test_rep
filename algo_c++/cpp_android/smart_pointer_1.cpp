#include <iostream>

using namespace std;

class Car {
public:
	void Go() {
		cout << "Car Go" << endl;
	}
};

/*
	개념 : 임의의 객체가 다른 타입의 포인터 역할을 하는 것
*/

class Ptr {
	Car* obj;

public:
	Ptr(Car* p = 0) : obj(p) {}
	~Ptr() { delete obj; }
	Car* operator->() { return obj; }
	Car& operator*() { return *obj; }
};

int main() {
	Ptr p = new Car;	// Ptr p(new Car)
	p->Go();			// (p.operator->())Go() 의 모양이지만 컴파일러가
					// (p.operator->())->Go()로 해석해 줌

	(*p).Go();
}