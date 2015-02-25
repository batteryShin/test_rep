#include <iostream>

using namespace std;

// ����ȭ ������ �ذ��ϱ� ���� Mutex�� ���
class Mutex {
public:
	void Lock() {
		cout << "Mutex Lock" << endl;
	}
	void UnLock() {
		cout << "Mutex UnLock" << endl;
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
		sLock.Lock();
		if( sInstance==0 )	sInstance = new Cursor;
		sLock.UnLock();

		return *sInstance;
	}
};

Mutex Cursor::sLock;
Cursor* Cursor::sInstance = 0;

int main() {
	Cursor& c1 = Cursor::getInstance();
}
