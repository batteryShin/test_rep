#include <algorithm>

using namespace std;

/*

라이브러리 설계자 입장에서는...

(1) 속도가 빨라야 한다.
(2) 알고리즘의 정책 변경이 가능해야 한다. 

*/

void Sort(int* x, int n, bool(*cmp)(int,int) ) {		// c표준의 qsort()가 이모양
	for(int i=0; i<n-1; i++) {
		for(int j=i+1; j<n; j++) {
//			if(x[i] > x[j]) {
			if( cmp(x[i],x[j]) ) {		// 비교 함수를 다시 호출한다. (2)의 관점으로 구현을 위해서...
				swap(x[i], x[j]);
			}
		}
	}
}

bool cmp1(int a, int b) { return a<b; }
bool cmp2(int a, int b) { return a>b; }

int main() {
	int x[10] = {1,3,5,7,9,2,4,6,8,10};
	Sort(x,10,cmp1);
}