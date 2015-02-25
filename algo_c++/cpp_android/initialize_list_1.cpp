/*
	장점 : 진짜 초기화. 객체형 멤버를 초기화 할 때는 속도가 빠르다.
			꼭 필요한 경우가 있다.

	단점 : 
*/
class Point {
	int x, y;

//	const int c = 0;	=> error
	const int c;		// ok. 선언부?

public:
	Point(int a=0, int b=0) : x(a),y(b),c(0) {	// 진짜 초기화
//		c = 0;		=> error. 대입이다.
		x = a;		// 대입
		y = b;
	}
};

int main() {
	Point p;

	AAA a = 0;		// 초기화

	AAA b;
	b = 0;			// 대입
}