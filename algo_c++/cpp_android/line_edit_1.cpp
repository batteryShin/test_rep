#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

// 1. �Է°��� ��ȿ���� validation �� �� �־�� �Ѵ�.
class LineEdit {
	string data;

public:
	string getData() {
		data.clear();
		while(1) {
			char c = getch();
			if( c==13 )	break;		// enter key

			if( isdigit(c) ) {
				data.push_back(c);
				cout << c;
			}
		}
		cout << endl;
		return data;
	}
};

int main() {
	LineEdit edit;
	while(1) {
		string s = edit.getData();
		cout << s << endl;
	}
}
