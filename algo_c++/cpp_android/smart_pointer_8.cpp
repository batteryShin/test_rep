#include <iostream>

using namespace std;

/*
����Ʈ �����ʹ�...
	1. template���� ������ ��
	2. ���� ���� ������ �ذ��ؾ� ��

���� ������ ����Ʈ ������ : �ڿ����� �뵵�θ� ����ϰ� ����� ������ �Ұ����ϵ���...
						�� ���������� �޸�/������ ������尡 ����.

*/

template<typename T> class UniquePtr {
	T* obj;

	UniquePtr(const UniquePtr&);
	void operator=(const UniquePtr&);

public:
	inline UniquePtr(T* p = 0) : obj(p) {}
	inline ~UniquePtr() { delete obj; }
	inline T* operator->() { return obj; }
	inline T& operator*() { return *obj; }
};

int main() {
	UniquePtr<int> p1 = new int;
	*p1 = 10;
	cout << *p1 << endl;
	
//	UniquePtr<int> p2 = p1;
}
