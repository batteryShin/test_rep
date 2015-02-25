#include <iostream>

using namespace std;

class Test {
	int data;

public:
	void f1() {
		cout << "f1" << endl;
	}

	void f2() {
		cout << "f2" << endl;
		return 0;
	}

protected:
	void f3() {
		cout << "f3" << endl;
		return data;			// this->data
	}

public:
	// �Ʒ� �Լ���? -> �߸��� null-pointer������ ���� ����ڵ�..
	// ���� : native/libs/binder/iinterface.cpp���� asBinder() �Լ�
	//			native/include/binder/iinterface.h
	int call_f3() {
		return this ? f3() : NULL;
	}
};

int main() {
	Test* p = 0;		// �޸� �Ҵ翡 �����ߴٰ� ����
	p->f1();			// ??? f1( p ) => f1(0)
//	p->f2();				// ??? error. Test��ü�� null�� ����
	p->call_f3();
}