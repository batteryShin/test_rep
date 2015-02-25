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
	// 아래 함수는? -> 잘못된 null-pointer참조에 대한 방어코드..
	// 참조 : native/libs/binder/iinterface.cpp에서 asBinder() 함수
	//			native/include/binder/iinterface.h
	int call_f3() {
		return this ? f3() : NULL;
	}
};

int main() {
	Test* p = 0;		// 메모리 할당에 실패했다고 가정
	p->f1();			// ??? f1( p ) => f1(0)
//	p->f2();				// ??? error. Test객체의 null을 참조
	p->call_f3();
}