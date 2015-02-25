#include <iostream>

using namespace std;

/*
멤버 data의 상태를 변경하지 않으면 반드시 상수함수로 해야 한다.
해당 클래스의 객체가 상수 객체 또는 상수 참조로 만들어질 때,
호출할 수 있게 해야 한다.
<ex> Rect의 getArea(), getWidth()등은 반드시 const 함수로 해야 한다.
*/

class Rect {
	int x, y, w, h;
public:
	int getArea() const {
		return w*h;
	}
};

// c++에서는 흔히 call by value 보다는 const &로 인자를 많이 전달
void foo(const Rect& r) {
	r.getArea();
}

int main() {
	Rect r;
	int n = r.getArea();
	foo(r);
}

/*
class Point {
public:
	int x, y;
	void set(int a, int b) {
		x = a;
		y = b;
	}

	void print() const {				// 상수 멤버 함수
		// x = 10;						// error. 상수 함수에서 모든 멤버 data는 상수이다.
		cout << x << ", " << y << endl;
	}
};

int main() {
	const Point p;
//	p.x = 10;
//	p.set(10,2);
	p.print();					// 호출되게 하려면 print()는 상수 함수 이어야 한다.
								// "상수 객체는 상수 함수만 호출 할 수 있다"
}
*/