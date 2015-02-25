#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

/*
	���ϴ� ���� �и��ϴ� 2���� ���
	1. ���ϴ� ���� �����Լ���	 (Template Method)
	2. ���ϴ� ���� �ٸ� Ŭ������ - ��ü �����ؾ� �ϹǷ� �������̽���� ���� (Strategy Pattern)

	QT��� ���¼ҽ��� QValidator�� QEdit�� ����ϰ� �䳻�� �ڵ�...
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
