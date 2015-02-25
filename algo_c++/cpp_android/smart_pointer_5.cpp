#include <iostream>

using namespace std;

class Car {
	//....
	int mCount;
public:
	Car() : mCount(0) {}
	~Car() { cout << "�ڵ��� �ı�" << endl; }

	void incStrong() { ++mCount; }
	void decStrong() { if( --mCount==0 ) delete this; }
};

// ��ü�� ��������� �ڵ� �����ϴ� ����Ʈ �����͸� ��������.
template<typename T> class sp {
	T* m_ptr;

public:
	sp(T* other = 0) : m_ptr(other) {
		if(m_ptr)	m_ptr->incStrong();
	}

	sp(const sp<T>& p) : m_ptr(p.m_ptr) {
		if(m_ptr)	m_ptr->incStrong();
	}

	~sp() {
		if(m_ptr)	m_ptr->decStrong();
	}

	T& operator*() { return *m_ptr; }
	T& operator->() { return m_ptr; }
};

int main() {
	sp<Car> p1 = new Car;
	sp<Car> p2 = p1;
}