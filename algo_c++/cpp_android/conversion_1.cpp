#include <iostream>

using namespace std;

class Point {
	int x, y;

public:
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}

	operator int() {
		return x;
	}

	// ��ȯ ������ : ���ڰ� 1���� ������, �ٸ� Ÿ��(int) -> ��ü(Point)���� �Ͻ��� ��ȯ�� ���.
	Point(int a) : x(a),y(0) {}
};

int main() {
	Point p1;
	Point p2(1,2);

	int n = p2;		// Point -> int : p2.operator int()
	p2 = n;			// int -> Point : n.operator Point() �̸� �Ǵµ� n�� ��ü�� �ƴ�.
					//					���� ��� ��ü�� ��ȯ������ �̿�.
}

/*
int main() {
	double d = 3.4;
	int n1 = d;

	Point p(1,2);
	int n2 = p;		// p.operator int() �Լ��� ������ ok.
}
*/