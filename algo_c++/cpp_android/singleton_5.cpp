#include <iostream>

using namespace std;

class Mutex {
public:
	void Lock() {
		cout << "Mutex Lock" << endl;
	}
	void UnLock() {
		cout << "Mutex UnLock" << endl;
	}

	// ������ �Ҹ��ڷ� ����ȭ �ڿ��� ���� - RAII(Resource Acquisition Is Initialize)
	class Autolock {
		Mutex& mLock;
	public:
		Autolock(Mutex& m) : mLock(m) {
			mLock.Lock();
		}
		~Autolock() {
			mLock.UnLock();
		}
	};
};



template<typename TYPE> class Singleton {
protected:
		Singleton() {}

private:
	Singleton(const Singleton& c);
	void operator=(const Singleton& c);

	static TYPE* sInstance;
	static Mutex sLock;

public:
	static TYPE& getInstance() {
		Mutex::Autolock al(sLock);
//		sLock.Lock();
		if( sInstance==0 )	sInstance = new TYPE;
//		sLock.UnLock();

		return *sInstance;
	}
};

template<typename TYPE> Mutex Singleton<TYPE>::sLock;
template<typename TYPE> TYPE* Singleton<TYPE>::sInstance = 0;
// Modern C++ ������ å 7�忡 singleton�� �޸� ������ �ٷ�...

// SensorManager�� Singleton���� ����� ���� ��...
// CRTP(Curiosly Recurring Template Pattern) : �θ𿡰� template ���ڷ� �ڽ��� Ŭ���� �̸��� �˷��ִ� ������ ���
class SensorManager : public Singleton< SensorManager > {

};

int main() {
	SensorManager& m1 = SensorManager::getInstance();
}
