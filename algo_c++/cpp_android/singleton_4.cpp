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
