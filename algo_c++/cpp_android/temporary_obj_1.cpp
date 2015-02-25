#include <iostream>

using namespace std;

struct Point {
	int x, y;
};

Point p = {1,2};

//Point foo() {					// 값리턴 : 임시객체를 만들어서 리턴한다.
Point& foo() {					// 참조리턴 : 리턴용 임시객체를 만들지 말라는 의도를 담은 코드
	return p;
}

int main() {
	foo().x = 10;
	cout << p.x << endl;
}