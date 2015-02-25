/*

일반 함수 포인터에 멤버 함수의 주소를 담을 수 없다.
일반 함수 포인터에 static 멤버 함수의 주소는 담을 수 있다.

*/

void foo() {}

class Dialog
{
public:
	void Close() {}
};

int main() {
	void(Dialog::*f3)() = &Dialog::Close;
//	f3();								// error. 객체(this)가 없다.

	Dialog dlg;
	(dlg.*f3)();							// OK.



//	void(*f1)() = &foo;
//	void(*f2)() = &Dialog::Close;		// Close에는 this가 있다.
}