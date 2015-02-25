/*
	1. 인터페이스 기반 설계로 동기화 여부를 교체 가능하게 하자.
	- 장점 : 실행시간에 정책을 교체할 수 있다(언제라도 setSync()를 호출하면 됨)
	- 단점 : 가상함수이므로 성능 저하가 있다.

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
	2. template 기반의 정책 교체 (단위전략 - policy base design)
	- 장점 : 가상함수가 아니고 인라인 함수. 빠르다.
	- 단점 : 실행 시간에 정책을 교체하기는 불가능.

	Modern C++ Design 책 참고...
		1개의 general한 스마트포인터 ( smart_pointer<int, NoCopy, MultiThread> p; <= 요런식으로 사용* )
*/
template<typename T, typename ThreadModel=MultiThread> class list : public ThreadModel {
public:
	void push_front(const T& a) {
		Lock();
		//....
		UnLock();
	}
};

//		동기화 정책을 담은 클래스를 설계
class SingleThread {
public:
	inline void Lock() {
		// 구현을 비워둔다.
	}
	inline void UnLock() {
		// 구현을 비워둔다.
	}
};

class MultiThread {
public:
	inline void Lock() {
		// 동기화 관련 코드를 제공한다.
	}		
	inline void UnLock() {
		// 동기화 관련 코드를 제공한다.
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
