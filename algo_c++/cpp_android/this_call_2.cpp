/*

�Ϲ� �Լ� �����Ϳ� ��� �Լ��� �ּҸ� ���� �� ����.
�Ϲ� �Լ� �����Ϳ� static ��� �Լ��� �ּҴ� ���� �� �ִ�.

*/

void foo() {}

class Dialog
{
public:
	void Close() {}
};

int main() {
	void(Dialog::*f3)() = &Dialog::Close;
//	f3();								// error. ��ü(this)�� ����.

	Dialog dlg;
	(dlg.*f3)();							// OK.



//	void(*f1)() = &foo;
//	void(*f2)() = &Dialog::Close;		// Close���� this�� �ִ�.
}