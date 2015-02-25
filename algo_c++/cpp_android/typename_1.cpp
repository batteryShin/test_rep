class AAA {
public:
	//...
	// static int DWORD;
	typedef int DWORD;
};

int p = 0;

template<typename T> void foo(T a) {
	typename T::DWORD * p;	// 해석??
							// 1. DWORD는 static 변수인데 곱하기 p하고 있다. - C++ default
							// 2. DWORD는 typedef된 타입이다. 포인터변수 p를 선언하고 있다. - typename 키워드 사용해야 함
}

int main() {
//	typename AAA::DWORD* p;		// error. typename은 T일때만 사용.

	AAA aaa;
	foo(aaa);
}