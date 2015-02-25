#include <iostream>
#include <memory>

using namespace std;

struct Node {
	int data;

/* 상호 참조가 발생할 때는 참조계수를 증가하면 안된다. */
//	shared_ptr<Node> next;
//	Node* next;
	weak_ptr<Node> next;	// shared_ptr<>과 호환되면서 참조계수를 증가하지 않는
							//	(또는 별도의 참조계수로 관리) 스마트 포인터
							// 안드로이드 : sp와 호환되면서 참조계수를 증가하지 않는
							//				(또는 별도의 참조계수로 관리) 스마트 포인터 wp


	~Node() {
		cout << "Destroy Node" << endl;
	}
};

int main() {
	shared_ptr<Node> p1( new Node );
	shared_ptr<Node> p2( new Node );

	p1->next = p2;
	p2->next = p1;
}