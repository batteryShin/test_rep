#include <iostream>

using namespace std;

/*
	���� ���
	- 1. Diamond ����� ������
		Diamond ����� �߻��Ҷ��� 1�� �ڽĿ��� �������� �ؾ��Ѵ�

*/


class X { public: int x; };
class A : virtual public X { public: int a; };
class B : public virtual X { public: int b; };

class C : public A, public B {};

int main() {
	C c;
	c.x = 10;
}