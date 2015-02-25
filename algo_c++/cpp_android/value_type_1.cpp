#include <iostream>
#include <vector>
#include <list>

using namespace std;

/*
	template ��� �����̳ʵ��� �ڽ��� �����ϴ� Ÿ���� ����.
	�� Ÿ���� �ܺο� �˸��� ���� �� �Ʒ��� ���� ����

template<typename T> class list {
public:
	typedef T value_type;
	//...
};

*/

// ���� : native/include/utils/Vector.h
template<typename T> void print(T& v) {
	typename T::value_type n = v.front();
	cout << n << endl;
}

/*
template<typename T> void print(vector<T>& v) {
	T n = v.front();
	cout << n << endl;
}
*/
/*
void print(vector<int>& v) {
	int n = v.front();
	cout << n << endl;
}
*/

int main() {
	list<double> v(10,3);		// 10���� 3���� �ʱ�ȭ
	print(v);

//	list<double>::value_type n;		// n�� double
}