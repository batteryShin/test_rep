#include <iostream>

using namespace std;

template<typename T> struct trait_array {
	enum { size = -1 };
	enum { value = false };
};

template<typename T, int N> struct trait_array<T[N]> {
	enum { size = N };
	enum { value = true };
};

template<typename T> void foo( const T& a ) {
	if( trait_array<T>::value ) {
		cout << trait_array<T>::size << " ũ���� �迭�Դϴ�" << endl;
	} else {
		cout << "�迭�� �ƴմϴ�" << endl;
	}
}



int main() {
	int x[10];
	foo(x);
}