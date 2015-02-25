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

	// 생성자 소멸자로 동기화 자원을 관리 - RAII(Resource Acquisition Is Initialize)
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
// Modern C++ 디자인 책 7장에 singleton의 메모리 해지를 다룸...

// SensorManager도 Singleton으로 만들고 싶을 때...
// CRTP(Curiosly Recurring Template Pattern) : 부모에게 template 인자로 자식의 클래스 이름을 알려주는 디자인 기술
class SensorManager : public Singleton< SensorManager > {

};

int main() {
	SensorManager& m1 = SensorManager::getInstance();
}
