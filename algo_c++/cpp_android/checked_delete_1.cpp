#include <iostream>
using namespace std;

class Test;		// 클래스 전방 선언 - 완전한 선언이 없어도 "포인터"는 만들 수 있음.
//Test* t;		<= 불완전 객체(incomplete object) : 전방 선언만 되어있는 포인터. delete시에 소멸자가 호출되지 않음.

void foo(Test* p) {
	// 요즘 c++ library들은 delete전에 불완전 객체인지 조사하는 경우가 많음(checked delete)
	enum { type_must_be_complete = sizeof(Test) };	// 완전한 객체만 크기를 구할 수 있음. 불완전 객체는 컴파일 에러.
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