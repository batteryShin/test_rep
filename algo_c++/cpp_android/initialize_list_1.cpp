/*
	���� : ��¥ �ʱ�ȭ. ��ü�� ����� �ʱ�ȭ �� ���� �ӵ��� ������.
			�� �ʿ��� ��찡 �ִ�.

	���� : 
*/
class Point {
	int x, y;

//	const int c = 0;	=> error
	const int c;		// ok. �����?

public:
	Point(int a=0, int b=0) : x(a),y(b),c(0) {	// ��¥ �ʱ�ȭ
//		c = 0;		=> error. �����̴�.
		x = a;		// ����
		y = b;
	}
};

int main() {
	Point p;

	AAA a = 0;		// �ʱ�ȭ

	AAA b;
	b = 0;			// ����
}