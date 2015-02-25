#include <iostream>

using namespace std;

struct Freer {
	inline void operator()(void* p) {
		cout << "free" << endl;
		free(p);
	}
};

// void* Ÿ������ delete�ϸ� �Ҹ��ڰ� ȣ����� �ʴ´�.
// ��Ȯ�� Ÿ���� �����ͷ� delete�ؾ� �Ѵ�.
template<typename T> struct DefaultDeleter {
	inline void operator()(T* p) {
		cout << "delete" << endl;
		delete p;
	}
};

template<typename T> struct DefaultDeleter<T[]> {
	inline void operator()(T* p) {
		cout << "delete[]" << endl;
		delete [] p;
	}
};

template<typename T, typename D = DefaultDeleter<T> > class UniquePtr {
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
	UniquePtr<int> p1 = new int;

//	UniquePtr<int[]> p2 = new int[10];	=> ���� �� ���� �����߻���.
}