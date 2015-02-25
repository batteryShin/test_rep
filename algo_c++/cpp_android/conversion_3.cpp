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
	Test t1(5);		// 1. ���� 1��¥�� ������ ȣ��
//	Test t2 = 5;	// 2. 5�� ��ȯ �����ڸ� ����ؼ� Test�� �ӽð�ü�� ���� ��,
					//		�ӽð�ü�� ���� �����ڸ� ����ؼ� t2�� ����

//	String16 s1 = "hello";		// error. explicit ������ ����
	String16 s2("hello");		// ok

//	addService("kr.co.lg.LedService");		// error. explicit ������ ����
	addService(String16("kr.co.lg.LedService"));	// ok
}
