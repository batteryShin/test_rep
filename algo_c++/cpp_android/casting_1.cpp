#include <iostream>

using namespace std;

/*
	C의 캐스팅은 비이성적(Unreasonable)이고 위험하다.
	그리하여, c++진영에서는 4개의 캐스팅 연산자를 만듦
		A. static_cast : 이성적이고 연관성이 있는 경우와 void* -> 다른 타입만 허용
		B. reinterpret_cast
		C. const_cast
		D. dynamic_cast
*/
int main() {
	int n = 3;

/*
	int* p1 = (int*)( malloc(100) );	// void* -> int* 암시적 변환 안됨, 명시적 변환 ok
	double* p2 = (double*)&n;		// int* -> double* 암시적 변환 안됨, 명시적 변환 ok
	*p2 = 3.4;						// 위험성 내포...
*/

/*
	int* p1 = static_cast<int*>( malloc(100) );
	double* p2 = reinterpret_cast<double*>(&n);
*/

	int a;
	cin >> a;
	const int c2 = a;		// 런 타임 상수

	const int c = 10;		// 컴파일 타임 상수
//	int* p = (int*)&c;		// 상수를 비상수를 가르키는 포인터에 담기. 암시적 변환 안됨, 명시적 변환 ok
//	int* p = reinterpret_cast<int*>(&c);
	int* p = const_cast<int*>(&c);
	*p = 20;
	cout << c << endl;
}