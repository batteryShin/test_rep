class Point {
	int x, y;
public:
	Point(int a, int b) {}
};

class Rect {
	Point p1;
	Point p2;
public:
	Rect() : p1(0,0), p2(0,0) {}		// 자식 instance의 생성자가 없는 경우에, 이렇게 초기화하여 해결해야...
};

int main() {
	Rect r;
}