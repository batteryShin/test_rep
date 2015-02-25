#include <iostream>

using namespace std;

// Traits ���...
template<typename T> struct trait_pointer {
	enum { value = false };
};

template<typename T> struct trait_pointer<T*> {
	enum { value = true };
};

template<typename T> void foo( const T& a ) {
	if( trait_pointer<T>::value ) {
		cout << "������ �Դϴ�." << endl;
	} else {
		cout << "�����Ͱ� �ƴմϴ�." << endl;
	}
};

int main() {
	int x = 0;
	foo( &x );
	foo( x );
}

/*
template<typename T> T Max(T a, T b) {
	return a<b? b : a;
}

int main() {
	int x = 10, y = 20;

	Max(x,y);
	Max(&x,&y);
}
*/