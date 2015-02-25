#include <iostream>

using namespace std;

class String16
{
public:
	explicit String16(const char* o) {};
};

void addService( String16 name ) {}

class Test {
	int value;

public:
	explicit Test( int n=0 ) : value(n) {}
};

int main() {
	Test t1(5);		// 1. 인자 1개짜리 생성자 호출
//	Test t2 = 5;	// 2. 5를 변환 생성자를 사용해서 Test의 임시객체로 만든 후,
					//		임시객체를 복사 생성자를 사용해서 t2에 복사

//	String16 s1 = "hello";		// error. explicit 구문에 의해
	String16 s2("hello");		// ok

//	addService("kr.co.lg.LedService");		// error. explicit 구문에 의해
	addService(String16("kr.co.lg.LedService"));	// ok
}
