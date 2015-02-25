/*
	1. ���Ҽ��� template�� ����� ���� : double�̸� �� �ɵ� �ϳ�, �ӵ� ������ ����

*/

template<typename T> class complex {
	T re;
	T im;

public:
	complex(T a=0, T b=0) : re(a),im(b) {}

	// template ���������(�Ϲ�ȭ�� ���� ������)
	// "U�� T�� ���� �� �� �ִٸ�, complex<U>�� complex<T>�� ����� �� �־�� �Ѵ�"
	// ���� : native/include/utils/StrongPointer.h
	template<typename U> complex(const complex<U>& c);

	// complex�� template�ε� ��� ģ���̴�.
	template<typename U> friend class complex;
};

template<typename T> template<typename U>
complex<T>::complex(const complex<U>& c) : re(c.re), im(c.im) {}

int main() {
	complex<int> c1(1,2.2);
	complex<int> c2 = c1;			// ���������. default�� �ְ�, ���ϴ� ������. ok.

	complex<double> c3 = c1;		// error. type�� �ٸ��Ƿ� ��������� ����.
}