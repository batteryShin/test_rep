#include <iostream>

using namespace std;

struct Point {
	int x, y;
};

Point p = {1,2};

//Point foo() {					// ������ : �ӽð�ü�� ���� �����Ѵ�.
Point& foo() {					// �������� : ���Ͽ� �ӽð�ü�� ������ ����� �ǵ��� ���� �ڵ�
	return p;
}

int main() {
	foo().x = 10;
	cout << p.x << endl;
}