#include <iostream>
#include <vector>
#include <list>

using namespace std;

/*
	template 기반 컨테이너들은 자신이 저장하는 타입이 있음.
	그 타입을 외부에 알리고 싶을 때 아래와 같이 설계

template<typename T> class list {
public:
	typedef T value_type;
	//...
};

*/

// 참조 : native/include/utils/Vector.h
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
	list<double> v(10,3);		// 10개를 3으로 초기화
	print(v);

//	list<double>::value_type n;		// n은 double
}