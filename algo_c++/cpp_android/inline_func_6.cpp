#include <iostream>
#include <algorithm>

using namespace std;

struct less {
	bool operator()(int a, int b) {
		return a<b;
	}
};
struct greater {
	bool operator()(int a, int b) {
		return a>b;
	}
};

bool cmp1(int a, int b) { return a<b; }
bool cmp2(int a, int b) { return a>b; }

int main() {
	int x[10] = {1,3,5,7,9,2,4,6,8,10};

/*
	sort()�� ��� ���ڴ� ���ø��Դϴ�.
	(1) ��å���� �Ϲ� �Լ��� ����� ���,
		���� : ��å�� �������� �����ص� sort() ����� �� ���̴�.
		���� : ��å�� �ζ��� ġȯ�� �� �������� ������.
*/
	sort(x, x+10, cmp1);				// sort(int*,int*,bool(*)(int,int));
	sort(x, x+10, cmp2);				// sort(int*,int*,bool(*)(int,int));



/*
	(2) ��å���� �Լ���ü�� ����� ���,
		���� : ��å�� �ζ��� ġȯ�ǹǷ� �ӵ��� ������.
		���� : ��å�� ������ŭ�� sort() ��� �����ȴ�.
*/
	less f1;
	greater f2;
	sort(x, x+10, f1);					// sort(int*,int*,less)
	sort(x, x+10, f2);					// sort(int*,int*,greater)

//	���� : �Լ� ���ڷ� �Լ� �����ڵ带 �����ϴ� ���ο� ����
//		  ���ڷ� ���޵� �����ΰ� sort()�ȿ��� �ζ��� ġȯ�˴ϴ�.
	sort(x, x+10, [](int a, int b) { return a<b; });
}