#include <iostream>

using namespace std;

/*
	�߻� Ŭ���� - ���� �����Լ��� 1�� �̻� �ִ� Ŭ����

	- �ǵ� : Ư�� �Լ��� �ڽĿ��� �ݵ�� ������ �����ϴ� ��.
*/

class Shape {
public:
	virtual void Draw() = 0;		// ���� �����Լ�(pure virtual function)
};

class Rect : public Shape {			// Draw()�� �����θ� �������� ������ ���� �߻� Ŭ����.
};

int main() {
//	Shape s;	// error. �߻�Ŭ������ ��ü�� ���� �� ����.
//	Rect r;		// error. �߻�Ŭ���� �̹Ƿ�..
}