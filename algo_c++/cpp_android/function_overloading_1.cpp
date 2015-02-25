//#include <iostream>

using namespace std;

//
/*

주제 1. 함수 오버로딩

 (1) 원리 : 컴파일 시간에 함수 이름 변경하기 - name mangling
 (2) 어셈 소스 보는 방법 : cl 소스이름.cpp /FAs => 소스이름.asm
						 g++ 소스이름.cpp -S => 소스이름.s
 (3) 컴파일 시간 문법이다. 실행 시 성능에는 영향을 주지 않는다.

*/
//

int square(int a) {
	return a*a;
}

double square(double a) {
	return a*a;
}

int main() {
	square(3);
	square(3.3);
}

