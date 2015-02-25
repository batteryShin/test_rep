#include <iostream>

using namespace std;

// Traits 기술...
template<typename T> struct trait_pointer {
	enum { value = false };
};

template<typename T> struct trait_pointer<T*> {
	enum { value = true };
};

template<typename T> void foo( const T& a ) {
	if( trait_pointer<T>::value ) {
		cout << "포인터 입니다." << endl;
	} else {
		cout << "포인터가 아닙니다." << endl;
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