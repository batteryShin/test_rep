class Point {
	int x, y;
public:
	Point(int a, int b) {}
};

class Rect {
	Point p1;
	Point p2;
public:
	Rect() : p1(0,0), p2(0,0) {}		// �ڽ� instance�� �����ڰ� ���� ��쿡, �̷��� �ʱ�ȭ�Ͽ� �ذ��ؾ�...
};

int main() {
	Rect r;
}