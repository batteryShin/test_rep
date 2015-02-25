#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

/*
	변하는 것을 분리하는 2가지 방법
	1. 변하는 것을 가상함수로	 (Template Method)
	2. 변하는 것을 다른 클래스로 - 교체 가능해야 하므로 인터페이스기반 설계 (Strategy Pattern)

	QT라는 오픈소스의 QValidator와 QEdit를 비슷하게 흉내낸 코드...
*/

class IValidator {
public:
	virtual bool validate(string s, char c) = 0;
	virtual bool iscomplete(string s) { return true; }
	virtual ~IValidator() {}
};

class LimitDigitValidator : public IValidator {
	int value;

public:
	LimitDigitValidator(int n) : value(n) {}
	
	virtual bool validate(string s, char c) {
		return (s.size()<value) && isdigit(c);
	}

	virtual bool iscomplete(string s) {
		return (s.size()==value);
	}
};

class LineEdit {
	string data;
	IValidator* pValidator;

public:
	void setValidator(IValidator* p) { pValidator = p; }

	string getData() {
		data.clear();
		while(1) {
			char c = getch();
			if( c==13 &&
				(pValidator==0 || pValidator->iscomplete(data)) ) {
					break;
			}

			if( pValidator==0 || pValidator->validate(data,c) ) {
				data.push_back(c);
				cout << c;
			}
		}
		cout << endl;
		return data;
	}
	
	virtual bool validate(string s,char c) {
		return isdigit(c);
	}
};

int main() {
	LineEdit edit;
	LimitDigitValidator v(5);
	edit.setValidator(&v);
	while(1) {
		string s = edit.getData();
		cout << s << endl;
	}
}
