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
	sort()의 모든 인자는 템플릿입니다.
	(1) 정책으로 일반 함수를 사용할 경우,
		장점 : 정책을 여러개로 변경해도 sort() 기계어는 한 개이다.
		단점 : 정책이 인라인 치환될 수 없음으로 느리다.
*/
	sort(x, x+10, cmp1);				// sort(int*,int*,bool(*)(int,int));
	sort(x, x+10, cmp2);				// sort(int*,int*,bool(*)(int,int));



/*
	(2) 정책으로 함수객체를 사용할 경우,
		장점 : 정책이 인라인 치환되므로 속도가 빠르다.
		단점 : 정책의 갯수만큼의 sort() 기계어가 생성된다.
*/
	less f1;
	greater f2;
	sort(x, x+10, f1);					// sort(int*,int*,less)
	sort(x, x+10, f2);					// sort(int*,int*,greater)

//	람다 : 함수 인자로 함수 구현코드를 전달하는 새로운 문법
//		  인자로 전달된 구현부가 sort()안에서 인라인 치환됩니다.
	sort(x, x+10, [](int a, int b) { return a<b; });
}