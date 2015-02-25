#include <iostream>

using namespace std;

// �� private ����� ����ϴ°�?
//	-> �θ�� ���� /

// list�� �̹� �ִ�.
#include <list>
#include <vector>
#include <deque>

/*
	stack�� �ʿ�
	1. stack�� ������.
	2. list�� ���� �������� ����ϸ� stack. list�� ��������.
		(Adapter ���� : ���� Ŭ������ �������̽�(�Լ��̸�)�� �����ؼ�
						Ŭ���̾�Ʈ�� �䱸�ϴ� �ٸ� Ŭ������ ����� �ִ� ��)

template<typename T> class stack : private list<T> {
public:
	void push( const T& p ) { list<T>::push_back(p); }
	void pop() { list<T>::pop_back(); }
	T& top() { return list<T>::back(); }
};
*/

/*
// SW ������ ��Ӱ� ������ �ִ�. -> ������ ���� ��찡 �� ����.
template<typename T,typename C = deque<T> > class stack {
	C st;
public:
	inline void push( const T& p ) { st.push_back(p); }
	inline void pop() { st.pop_back(); }
	inline T& top() { return st.back(); }
};
*/

#include <stack>		// ������ ������ stack. stack adapter��� �Ҹ�


int main() {
	stack<int> s;
	stack<int,vector<int> > s2;
	stack<int,list<int> > s3;
	s.push(10);
//	s.push_front(30);		// ������� �Ǽ�...private ���� �����ڸ� ���� ����
	cout << s.top() << endl;
}