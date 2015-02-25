/*
인라인 함수

장점 : 기계어 코드가 치환 되므로 빠르다.
단점 : 여러번 치환되면 목적 코드의 크기가 커질 수 있다.

*/

int Add1(int a, int b) {
	return a+b;
}

inline int Add2(int a, int b) {
	return a+b;
}

int main() {
	int n1 = Add1(1,2);
	int n2 = Add2(1,2);
}