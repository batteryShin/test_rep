#include <iostream>

using namespace std;

/*
	C�� ĳ������ ���̼���(Unreasonable)�̰� �����ϴ�.
	�׸��Ͽ�, c++���������� 4���� ĳ���� �����ڸ� ����
		A. static_cast : �̼����̰� �������� �ִ� ���� void* -> �ٸ� Ÿ�Ը� ���
		B. reinterpret_cast
		C. const_cast
		D. dynamic_cast
*/
int main() {
	int n = 3;

/*
	int* p1 = (int*)( malloc(100) );	// void* -> int* �Ͻ��� ��ȯ �ȵ�, ����� ��ȯ ok
	double* p2 = (double*)&n;		// int* -> double* �Ͻ��� ��ȯ �ȵ�, ����� ��ȯ ok
	*p2 = 3.4;						// ���輺 ����...
*/

/*
	int* p1 = static_cast<int*>( malloc(100) );
	double* p2 = reinterpret_cast<double*>(&n);
*/

	int a;
	cin >> a;
	const int c2 = a;		// �� Ÿ�� ���

	const int c = 10;		// ������ Ÿ�� ���
//	int* p = (int*)&c;		// ����� ������ ����Ű�� �����Ϳ� ���. �Ͻ��� ��ȯ �ȵ�, ����� ��ȯ ok
//	int* p = reinterpret_cast<int*>(&c);
	int* p = const_cast<int*>(&c);
	*p = 20;
	cout << c << endl;
}