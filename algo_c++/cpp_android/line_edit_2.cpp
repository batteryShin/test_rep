#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

/*
 1. 입력값의 유효성을 validation 할 수 있어야 한다.

 2. validation 정책은 교체가 가능해야 한다.


*/
class LineEdit {
	string data;

public:

	// 변하지 않는 전체 알고리즘에서 변해야 하는 정책 부분이 있다면, 가상함수로 뽑아낸다.
	virtual bool validate(char c) {
		return isdigit(c);
	}

	string getData() {
		data.clear();
		while(1) {
			char c = getch();
			if( c==13 )	break;		// enter key

			if( validate(c) ) {
				data.push_back(c);
				cout << c;
			}
		}
		cout << endl;
		return data;
	}
};

// 이제 validation 정책을 변경하려면 자식클래스를 만들어서 가상함수를 재정의한다.
class AddressEdit : public LineEdit {
	virtual bool validate(char c) {
		return true;
	}
};

int main() {
	AddressEdit edit;
	while(1) {
		string s = edit.getData();
		cout << s << endl;
	}
}
