#include <iostream>

using namespace std;

/*
스마트 포인터는...
	1. template으로 만들어야 함
	2. 얕은 복사 문제를 해결해야 함
*/


template<typename T> class Ptr {
	T* obj;

public:
	Ptr(T* p = 0) : obj(p) {}
	~Ptr() { delete obj; }
	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};

int main() {
	Ptr<int> p1 = new int;
	*p1 = 10;
	cout << *p1 << endl;
	
	Ptr<int> p2 = p1;
}
