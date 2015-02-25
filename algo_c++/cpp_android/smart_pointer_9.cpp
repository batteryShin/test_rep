#include <iostream>

using namespace std;

struct Freer {
	inline void operator()(void* p) {
		cout << "free" << endl;
		free(p);
	}
};

// void* 타입으로 delete하면 소멸자가 호출되지 않는다.
// 정확한 타입의 포인터로 delete해야 한다.
template<typename T> struct DefaultDeleter {
	inline void operator()(T* p) {
		cout << "delete" << endl;
		delete p;
	}
};

template<typename T, typename D=DefalutDelete<T> > class UniquePtr {
	T* obj;

	UniquePtr(const UniquePtr&);
	void operator=(const UniquePtr&);

public:
	inline UniquePtr(T* p = 0) : obj(p) {}
	inline ~UniquePtr() {
		D d;
		d(obj);
	}
	inline T* operator->() { return obj; }
	inline T& operator*() { return *obj; }
};

int main() {
	UniquePtr<int,DefaultDelete<int> > p1 = new int;
	UniquePtr<int> p11 = new int;
	UniquePtr<int,Freer> p2 = static_cast<int*>(malloc(100));
}