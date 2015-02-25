#include <iostream>
using namespace std;

class Test;		// Ŭ���� ���� ���� - ������ ������ ��� "������"�� ���� �� ����.
//Test* t;		<= �ҿ��� ��ü(incomplete object) : ���� ���� �Ǿ��ִ� ������. delete�ÿ� �Ҹ��ڰ� ȣ����� ����.

void foo(Test* p) {
	// ���� c++ library���� delete���� �ҿ��� ��ü���� �����ϴ� ��찡 ����(checked delete)
	enum { type_must_be_complete = sizeof(Test) };	// ������ ��ü�� ũ�⸦ ���� �� ����. �ҿ��� ��ü�� ������ ����.
	delete p;
}

class Test {
public:
	Test() { cout << "Test()" << endl; }
	~Test() { cout << "~Test()" << endl; }
};

int main() {
	Test* p = new Test;
	foo(p);	
}