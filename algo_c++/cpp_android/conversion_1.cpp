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

	// 변환 생성자 : 인자가 1개인 생성자, 다른 타입(int) -> 객체(Point)로의 암시적 변환을 허용.
	Point(int a) : x(a),y(0) {}
};

int main() {
	Point p1;
	Point p2(1,2);

	int n = p2;		// Point -> int : p2.operator int()
	p2 = n;			// int -> Point : n.operator Point() 이면 되는데 n은 객체가 아님.
					//					변경 대상 객체의 변환생성자 이용.
}

/*
int main() {
	double d = 3.4;
	int n1 = d;

	Point p(1,2);
	int n2 = p;		// p.operator int() 함수가 있으면 ok.
}
*/