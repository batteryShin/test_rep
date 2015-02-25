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

	// �Ʒ� �Լ��� static ��� �̾�� �ϴ� ������ ��Ȯ�� �˾ƾ� ��.(this�� ���ڷ� ���޵Ǹ� �ȵǹǷ�?)
	static DWORD __stdcall _threadLoop(void* user) {
		Thread* const self = static_cast<Thread*>(user);
		// �ٽ� �����Լ� ȣ��
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
	t.run();						// �� ���� thread�� �����Ǿ threadLoop()�� �����ؾ� �մϴ�.
	getch();
}

/*
DWORD __stdcall foo(void* p) {
	cout << "foo" << endl;
	return 0;
}

int main() {
	CreateThread( 0, 0, foo, "A", 0, 0);			// windows���� thread ����� �Լ�
													// linux : pthread_create()
	getch();
}
*/