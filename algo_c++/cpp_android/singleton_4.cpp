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
	}
};



class Cursor {
private:
	Cursor() {}
	Cursor(const Cursor& c);
	void operator=(const Cursor& c);

	static Cursor* sInstance;
	static Mutex sLock;

public:
	static Cursor& getInstance() {
		Mutex::Autolock al(sLock);
//		sLock.Lock();
		if( sInstance==0 )	sInstance = new Cursor;
//		sLock.UnLock();

		return *sInstance;
	}
};

Mutex Cursor::sLock;
Cursor* Cursor::sInstance = 0;

int main() {
	Cursor& c1 = Cursor::getInstance();
}
