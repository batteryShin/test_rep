#include <iostream>

using namespace std;

/*
��� data�� ���¸� �������� ������ �ݵ�� ����Լ��� �ؾ� �Ѵ�.
�ش� Ŭ������ ��ü�� ��� ��ü �Ǵ� ��� ������ ������� ��,
ȣ���� �� �ְ� �ؾ� �Ѵ�.
<ex> Rect�� getArea(), getWidth()���� �ݵ�� const �Լ��� �ؾ� �Ѵ�.
*/

class Rect {
	int x, y, w, h;
public:
	int getArea() const {
		return w*h;
	}
};

// c++������ ���� call by value ���ٴ� const &�� ���ڸ� ���� ����
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

	void print() const {				// ��� ��� �Լ�
		// x = 10;						// error. ��� �Լ����� ��� ��� data�� ����̴�.
		cout << x << ", " << y << endl;
	}
};

int main() {
	const Point p;
//	p.x = 10;
//	p.set(10,2);
	p.print();					// ȣ��ǰ� �Ϸ��� print()�� ��� �Լ� �̾�� �Ѵ�.
								// "��� ��ü�� ��� �Լ��� ȣ�� �� �� �ִ�"
}
*/