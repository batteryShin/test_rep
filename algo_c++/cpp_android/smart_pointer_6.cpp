#include <iostream>

using namespace std;

// sp를 사용하려면 반드시 RefBase 클래스의 자식으로 만들어야 한다.
// 참조계수를 객체에 포함 시키자
class RefBase {
	//....
	int mCount;
public:
	RefBase() : mCount(0) {}
	virtual ~RefBase() {}		// 가상 소멸자

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

class LedService : public RefBase {
public:
	~LedService() {
		cout << "~LedService" << endl;
	}
};

int main() {
	sp<LedService> p1 = new LedService;

//	sp<int> p2 = new int; => error. int에는 incStrong()/decStrong()가 없다

}