#include <algorithm>

using namespace std;

/*

���̺귯�� ������ ���忡����...

(1) �ӵ��� ����� �Ѵ�.
(2) �˰����� ��å ������ �����ؾ� �Ѵ�. 

*/

void Sort(int* x, int n, bool(*cmp)(int,int) ) {		// cǥ���� qsort()�� �̸��
	for(int i=0; i<n-1; i++) {
		for(int j=i+1; j<n; j++) {
//			if(x[i] > x[j]) {
			if( cmp(x[i],x[j]) ) {		// �� �Լ��� �ٽ� ȣ���Ѵ�. (2)�� �������� ������ ���ؼ�...
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