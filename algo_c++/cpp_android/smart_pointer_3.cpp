#include <iostream>

using namespace std;

#include <memory>

int main() {
	sharted_ptr<int> p1( new int );
	*p1 = 10;

	shared_ptr<int> p2 = p1;	// �� ���� ���� ����� �����մϴ�.

	cout << *p2 << endl;
}
