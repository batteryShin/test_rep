//#include <iostream>

using namespace std;

//
/*

���� 1. �Լ� �����ε�

 (1) ���� : ������ �ð��� �Լ� �̸� �����ϱ� - name mangling
 (2) ��� �ҽ� ���� ��� : cl �ҽ��̸�.cpp /FAs => �ҽ��̸�.asm
						 g++ �ҽ��̸�.cpp -S => �ҽ��̸�.s
 (3) ������ �ð� �����̴�. ���� �� ���ɿ��� ������ ���� �ʴ´�.

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

