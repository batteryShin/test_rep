/*
	1. 복소수를 template로 만드는 이유 : double이면 다 될듯 하나, 속도 문제가 있음

*/

template<typename T> class complex {
	T re;
	T im;

public:
	complex(T a=0, T b=0) : re(a),im(b) {}

	// template 복사생성자(일반화된 복사 생성자)
	// "U가 T로 복사 될 수 있다면, complex<U>는 complex<T>로 복사될 수 있어야 한다"
	// 참조 : native/include/utils/StrongPointer.h
	template<typename U> complex(const complex<U>& c);

	// complex는 template인데 모두 친구이다.
	template<typename U> friend class complex;
};

template<typename T> template<typename U>
complex<T>::complex(const complex<U>& c) : re(c.re), im(c.im) {}

int main() {
	complex<int> c1(1,2.2);
	complex<int> c2 = c1;			// 복사생성자. default가 있고, 원하는 동작임. ok.

	complex<double> c3 = c1;		// error. type이 다르므로 복사생성자 없음.
}