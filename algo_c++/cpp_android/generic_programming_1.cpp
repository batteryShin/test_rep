#include <iostream>

using namespace std;

// 1.strchr()의 검색 구간의 일반화 - 부분 문자열 검색이 가능하도록...

/*
아래와 같이 사용했을 경우의 문제.
	1. 구간의 타입과 찾고자 하는 요소의 타입이 연관됨.
		double 배열에서 int를 찾을 수 없음.
	2. T* 라고 표현하면 진짜 포인터만 사용 가능. 스마트 포인터 사용 불가.
*/
//template<typename T> T* xfind(T* first, T* last, T c) {
template<typename T1, typename T2> T1 xfind(T1 first, T1 last, T2 c) {
	while( first!=last && *first!=c )	++first;

	return first; // !=last ? first : 0;
}


/*
// [first,last) 사이의 부분 문자열 검색. last는 검색 대상이 아님
char* xstrchr(char* first, char* last, char c) {
	while( first!=last && *first!=c )	++first;

	return first!=last ? first : 0;
}
*/
int main() {
	char s[] = "abcdefg";

	char* p = strchr(s,'c');
	char* p2 = xfind(s,s+4,'e');

	double x[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
	double* p3 = xfind(x, x+10, 5);

	if( p3==x+10 ) {
		cout << "찾을 수 없습니다." << endl;
	} else {
		cout << *p << " " << *p2 << " " << *p3 << endl;
	}
}