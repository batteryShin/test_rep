class Point {
	int x, y;

public:
	void set( int a, int b ) {		// void set( Point* const this, int a, int b )
		x = a;						// this->x = a;
		y = b;						// this->y = b;
	}

	static void foo(int a) {
		x = a;
	}
};

int main() {
	Point::foo(10);					// static 멤버함수는 객체 없이 호출 가능.

	Point p1, p2;
	p1.set(10,20);					// set(&p1, 10, 20)으로 컴파일 됩니다.
									// (1) 진짜 인자는 stack으로 보내고,
									//		push 20
									//		push 10
									// (2) 객체주소는 레지스터에 담은 후,
									//		mov ecx, &p1
									// (3) 이제 함수 호출
									//		call ?set@@xxxx
}