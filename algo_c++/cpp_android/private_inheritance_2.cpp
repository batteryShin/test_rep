#include <iostream>

using namespace std;

// 왜 private 상속을 사용하는가?
//	-> 부모로 부터 /

// list가 이미 있다.
#include <list>
#include <vector>
#include <deque>

/*
	stack이 필요
	1. stack을 만들자.
	2. list를 한쪽 방향으로 사용하면 stack. list를 재사용하자.
		(Adapter 패턴 : 기존 클래스의 인터페이스(함수이름)을 변경해서
						클라이언트가 요구하는 다른 클래스를 만들어 주는 것)

template<typename T> class stack : private list<T> {
public:
	void push( const T& p ) { list<T>::push_back(p); }
	void pop() { list<T>::pop_back(); }
	T& top() { return list<T>::back(); }
};
*/

/*
// SW 재사용은 상속과 포함이 있다. -> 포함이 좋은 경우가 더 많다.
template<typename T,typename C = deque<T> > class stack {
	C st;
public:
	inline void push( const T& p ) { st.push_back(p); }
	inline void pop() { st.pop_back(); }
	inline T& top() { return st.back(); }
};
*/

#include <stack>		// 동일한 원리의 stack. stack adapter라고 불림


int main() {
	stack<int> s;
	stack<int,vector<int> > s2;
	stack<int,list<int> > s3;
	s.push(10);
//	s.push_front(30);		// 사용자의 실수...private 접근 변경자를 통해 막음
	cout << s.top() << endl;
}