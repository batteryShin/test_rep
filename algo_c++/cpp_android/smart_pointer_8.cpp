#include <iostream>

using namespace std;

/*
스마트 포인터는...
	1. template으로 만들어야 함
	2. 얕은 복사 문제를 해결해야 함

복사 금지의 스마트 포인터 : 자원관리 용도로만 사용하고 복사와 대입은 불가능하도록...
						좀 불편하지만 메모리/성능의 오버헤드가 없다.

*/

template<typename T> class UniquePtr {
	T* obj;

	UniquePtr(const UniquePtr&);
	void operator=(const UniquePtr&);

public:
	inline UniquePtr(T* p = 0) : obj(p) {}
	inline ~UniquePtr() { delete obj; }
	inline T* operator->() { return obj; }
	inline T& operator*() { return *obj; }
};

int main() {
	UniquePtr<int> p1 = new int;
	*p1 = 10;
	cout << *p1 << endl;
	
//	UniquePtr<int> p2 = p1;
}
