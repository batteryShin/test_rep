#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

/*
 1. �Է°��� ��ȿ���� validation �� �� �־�� �Ѵ�.

 2. validation ��å�� ��ü�� �����ؾ� �Ѵ�.


*/
class LineEdit {
	string data;

public:

	// ������ �ʴ� ��ü �˰��򿡼� ���ؾ� �ϴ� ��å �κ��� �ִٸ�, �����Լ��� �̾Ƴ���.
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

// ���� validation ��å�� �����Ϸ��� �ڽ�Ŭ������ ���� �����Լ��� �������Ѵ�.
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
