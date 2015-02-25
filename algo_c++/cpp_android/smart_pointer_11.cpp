#include <iostream>

using namespace std;

struct Freer {
	inline void operator()(void* p) {
		enum { type_must_be_complete = sizeof(p) };
		cout << "free" << endl;
		free(p);
	}
};

// void* Ÿ������ delete�ϸ� �Ҹ��ڰ� ȣ����� �ʴ´�.
// ��Ȯ�� Ÿ���� �����ͷ� delete�ؾ� �Ѵ�.
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
	T* obj;		// error. int[]�� ��� int[]* obj; ��� Ʋ�� ����.

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

// []�� ���ؼ� �κ� ����ȭ �Ѵ�. �κ� ����ȭ �� ���� ����Ʈ ���ڴ� ǥ������ ����.
// ǥ������ �ʾƵ� primary template�� ���� �����.
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

	// �ȵ���̵忡���� �迭 �������� ->, * �����ڸ� ������.
//	inline T* operator->() { return obj; }
//	inline T& operator*() { return *obj; }
	inline T& operator[](int index) { return obj[index]; }
};

int main() {
	UniquePtr<int> p1(new int);

	UniquePtr<int[]> p2(new int[10]);
	p2[0] = 10;

	*p1 = 10;	// ok
//	*p2 = 10;	=> error. *�����ڸ� �����߱� ������, �迭������ []�� ��
}
