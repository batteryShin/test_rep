#include <iostream>

using namespace std;

struct Freer {
	inline void operator()(void* p) {
		enum { type_must_be_complete = sizeof(p) };
		cout << "free" << endl;
		free(p);
	}
};

// void* 타입으로 delete하면 소멸자가 호출되지 않는다.
// 정확한 타입의 포인터로 delete해야 한다.
template<typename T> struct DefaultDeleter {
	inline void operator()(T* p) {
		enum { type_must_be_complete = sizeof(p) };
		cout << "delete" << endl;
		delete p;
	}
};

template<typename T> struct DefaultDeleter<T[]> {
	inline void operator()(T* p) {
		enum { type_must_be_complete = sizeof(p) };
		cout << "delete[]" << endl;
		delete [] p;
	}
};

template<typename T, typename D = DefaultDeleter<T> > class UniquePtr {
	T* obj;		// error. int[]의 경우 int[]* obj; 라는 틀린 문법.

	explicit UniquePtr(const UniquePtr&);
	void operator=(const UniquePtr&);

public:
	inline explicit UniquePtr(T* p = 0) : obj(p) {}
	inline ~UniquePtr() {
		D d;
		d(obj);
	}
	inline T* operator->() { return obj; }
	inline T& operator*() { return *obj; }
};

// []를 위해서 부분 전문화 한다. 부분 전문화 할 때는 디폴트 인자는 표시하지 않음.
// 표시하지 않아도 primary template을 보고 적용됨.
template<typename T, typename D> class UniquePtr<T[],D> {
	T* obj;

	explicit UniquePtr(const UniquePtr&);
	void operator=(const UniquePtr&);

public:
	inline explicit UniquePtr(T* p = 0) : obj(p) {}
	inline ~UniquePtr() {
		D d;
		d(obj);
	}

	// 안드로이드에서는 배열 버전에서 ->, * 연산자를 제거함.
//	inline T* operator->() { return obj; }
//	inline T& operator*() { return *obj; }
	inline T& operator[](int index) { return obj[index]; }
};

int main() {
	UniquePtr<int> p1(new int);

	UniquePtr<int[]> p2(new int[10]);
	p2[0] = 10;

	*p1 = 10;	// ok
//	*p2 = 10;	=> error. *연산자를 제거했기 때문에, 배열버전은 []만 됨
}
