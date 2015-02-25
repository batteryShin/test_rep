#include <iostream>

using namespace std;

// CRTP�� ����ؼ� ���� �Ҹ����� overhead�� �����ϴ� ���..
// WTL�̶�� Windows OS�� ���¼ҽ��� �Ʒ�ó�� �����Ǿ� ����.
template<typename T> class Window {
public:
	void msgLoop() {
		(static_cast<T*>(this))->onClick();		// onClick() -> this->onClick() -> onClick(this)
	}

	void onClick() {}
};

class MyWindow : public Window<MyWindow> {
public:
	void onClick() { cout << "MyWindow onClick" << endl; }
};

int main() {
	MyWindow w;
	w.msgLoop();
}