#include <iostream>

using namespace std;

// CRTP를 사용해서 가상 소멸자의 overhead를 제거하는 기술..
// WTL이라는 Windows OS용 오픈소스가 아래처럼 구현되어 있음.
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