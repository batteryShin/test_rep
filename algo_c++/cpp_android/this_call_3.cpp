#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

class Thread
{
public:
	void run() {
		CreateThread(0, 0, _threadLoop, this, 0, 0);
	}

	// 아래 함수가 static 멤버 이어야 하는 이유를 정확히 알아야 함.(this가 인자로 전달되면 안되므로?)
	static DWORD __stdcall _threadLoop(void* user) {
		Thread* const self = static_cast<Thread*>(user);
		// 다시 가상함수 호출
		self->threadLoop();
		return 0;
	}
	
	virtual bool threadLoop() {
		return false;
	}
};

class MyThread : public Thread
{
public:
	virtual bool threadLoop() {
		cout << "MyThread threadLoop" << endl;
		return false;
	}
};

int main() {
	MyThread t;
	t.run();						// 이 순간 thread가 생성되어서 threadLoop()를 실행해야 합니다.
	getch();
}

/*
DWORD __stdcall foo(void* p) {
	cout << "foo" << endl;
	return 0;
}

int main() {
	CreateThread( 0, 0, foo, "A", 0, 0);			// windows에서 thread 만드는 함수
													// linux : pthread_create()
	getch();
}
*/