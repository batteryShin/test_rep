#include <iostream>

using namespace std;

template<typename T> struct Node {
	T data;
	Node* next;
	Node(T a, Node* n) : data(a),next(n) {}
};

// slist�ȿ� �ִ� Node�� ����Ű�� ����Ʈ������(�ݺ���)
template<typename T> class slist_iterator {
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = 0) : current(p) {}

	// xfind�� ���������� ++, !=, ==, * ������ �����
	inline slist_iterator& operator++() {
		current = current->next;
		return *this;
	}

	inline T& operator*() {
		return current->data;
	}

	inline bool operator!=(const slist_iterator& p) {
		return current!=p.current;
	}

	inline bool operator==(const slist_iterator& p) {
		return current==p.current;
	}
};

template<typename T> class slist {
	Node<T>* head;
public:
	slist() : head(0) {}
	void push_front(const T& a) {
		head = new Node<T>(a,head);
	}

	// ��� �����̳ʴ� �ڽ��� �ݺ��� �̸��� iterator��� ��ӵ� ������ �̸�����
	// �ܺο� �����ϱ�� ���
	typedef slist_iterator<T> iterator;

	// ��� �����̳� �����ڴ� �ڽ��� ���۰� ������ ������ ����Ű�� �ݺ��ڸ�
	// �����ϴ� �Լ��� �ݵ�� �����ϱ�� ���.
	iterator begin() { return iterator(head); }
	iterator end() { return iterator(0);	}
};

template<typename T1, typename T2> T1 xfind(T1 first, T1 last, T2 c) {
	while( first!=last && *first!=c )	++first;

	return first; // !=last ? first : 0;
}

int main() {
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);
	s.push_front(50);

	slist<int>::iterator p = s.begin();
	while( p!=s.end() ) {
		cout << *p << endl;
		++p;
	}

	cout << endl;
	slist<int>::iterator p2 = xfind(s.begin(),s.end(),20);
	cout << *p2 << endl;
}