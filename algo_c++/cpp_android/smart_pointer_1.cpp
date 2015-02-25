#include <iostream>

using namespace std;

class Car {
public:
	void Go() {
		cout << "Car Go" << endl;
	}
};

/*
	���� : ������ ��ü�� �ٸ� Ÿ���� ������ ������ �ϴ� ��
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
	p->Go();			// (p.operator->())Go() �� ��������� �����Ϸ���
					// (p.operator->())->Go()�� �ؼ��� ��

	(*p).Go();
}