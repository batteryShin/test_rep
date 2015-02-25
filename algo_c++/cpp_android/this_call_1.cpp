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
	Point::foo(10);					// static ����Լ��� ��ü ���� ȣ�� ����.

	Point p1, p2;
	p1.set(10,20);					// set(&p1, 10, 20)���� ������ �˴ϴ�.
									// (1) ��¥ ���ڴ� stack���� ������,
									//		push 20
									//		push 10
									// (2) ��ü�ּҴ� �������Ϳ� ���� ��,
									//		mov ecx, &p1
									// (3) ���� �Լ� ȣ��
									//		call ?set@@xxxx
}