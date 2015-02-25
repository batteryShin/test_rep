#include <iostream>

using namespace std;

class Car {
	//....
	int mCount;
public:
	Car() : mCount(0) {}
	~Car() { cout << "자동차 파괴" << endl; }

	void incStrong() { ++mCount; }
	void decStrong() { if( --mCount==0 ) delete this; }
};

// 객체의 참조계수를 자동 증가하는 스마트 포인터를 도입하자.
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