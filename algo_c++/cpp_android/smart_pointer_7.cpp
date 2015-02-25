#include <iostream>
#include <memory>

using namespace std;

struct Node {
	int data;

/* ��ȣ ������ �߻��� ���� ��������� �����ϸ� �ȵȴ�. */
//	shared_ptr<Node> next;
//	Node* next;
	weak_ptr<Node> next;	// shared_ptr<>�� ȣȯ�Ǹ鼭 ��������� �������� �ʴ�
							//	(�Ǵ� ������ ��������� ����) ����Ʈ ������
							// �ȵ���̵� : sp�� ȣȯ�Ǹ鼭 ��������� �������� �ʴ�
							//				(�Ǵ� ������ ��������� ����) ����Ʈ ������ wp


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