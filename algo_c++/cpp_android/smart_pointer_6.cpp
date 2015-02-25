#include <iostream>

using namespace std;

// sp�� ����Ϸ��� �ݵ�� RefBase Ŭ������ �ڽ����� ������ �Ѵ�.
// ��������� ��ü�� ���� ��Ű��
class RefBase {
	//....
	int mCount;
public:
	RefBase() : mCount(0) {}
	virtual ~RefBase() {}		// ���� �Ҹ���

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

class LedService : public RefBase {
public:
	~LedService() {
		cout << "~LedService" << endl;
	}
};

int main() {
	sp<LedService> p1 = new LedService;

//	sp<int> p2 = new int; => error. int���� incStrong()/decStrong()�� ����

}