/*
	1. �������̽� ��� ����� ����ȭ ���θ� ��ü �����ϰ� ����.
	- ���� : ����ð��� ��å�� ��ü�� �� �ִ�(������ setSync()�� ȣ���ϸ� ��)
	- ���� : �����Լ��̹Ƿ� ���� ���ϰ� �ִ�.

class ISync {
public:
	virtual void Lock() = 0;
	virtual void UnLock() = 0;
	virtual ~ISync() {}
};

template<typename T> class list {
	ISync* pSync;

public:
	void setSync(ISync* p) { pSync = p; }

	void push_front(const T& a) {
		pSync->Lock();
		//...
		pSync->UnLock();
	}
};

list<int> st;

int main() {
	st.push_front(10);
}
*/

/*
	2. template ����� ��å ��ü (�������� - policy base design)
	- ���� : �����Լ��� �ƴϰ� �ζ��� �Լ�. ������.
	- ���� : ���� �ð��� ��å�� ��ü�ϱ�� �Ұ���.

	Modern C++ Design å ����...
		1���� general�� ����Ʈ������ ( smart_pointer<int, NoCopy, MultiThread> p; <= �䷱������ ���* )
*/
template<typename T, typename ThreadModel=MultiThread> class list : public ThreadModel {
public:
	void push_front(const T& a) {
		Lock();
		//....
		UnLock();
	}
};

//		����ȭ ��å�� ���� Ŭ������ ����
class SingleThread {
public:
	inline void Lock() {
		// ������ ����д�.
	}
	inline void UnLock() {
		// ������ ����д�.
	}
};

class MultiThread {
public:
	inline void Lock() {
		// ����ȭ ���� �ڵ带 �����Ѵ�.
	}		
	inline void UnLock() {
		// ����ȭ ���� �ڵ带 �����Ѵ�.
	}
};

list<int,SingleThread> st;
list<int,MultiThread> st2;

/*
template<typename T> class list {
public:
	void push_front(const T& a) {
	}
};

list<int> st;
*/

int main() {
	st.push_front(10);
}
