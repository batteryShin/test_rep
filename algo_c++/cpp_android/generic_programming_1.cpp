#include <iostream>

using namespace std;

// 1.strchr()�� �˻� ������ �Ϲ�ȭ - �κ� ���ڿ� �˻��� �����ϵ���...

/*
�Ʒ��� ���� ������� ����� ����.
	1. ������ Ÿ�԰� ã���� �ϴ� ����� Ÿ���� ������.
		double �迭���� int�� ã�� �� ����.
	2. T* ��� ǥ���ϸ� ��¥ �����͸� ��� ����. ����Ʈ ������ ��� �Ұ�.
*/
//template<typename T> T* xfind(T* first, T* last, T c) {
template<typename T1, typename T2> T1 xfind(T1 first, T1 last, T2 c) {
	while( first!=last && *first!=c )	++first;

	return first; // !=last ? first : 0;
}


/*
// [first,last) ������ �κ� ���ڿ� �˻�. last�� �˻� ����� �ƴ�
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
		cout << "ã�� �� �����ϴ�." << endl;
	} else {
		cout << *p << " " << *p2 << " " << *p3 << endl;
	}
}