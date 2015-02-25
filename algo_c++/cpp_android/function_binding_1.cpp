#include <iostream>

using namespace std;

class Animal {
public:
	void Cry() {
		cout << "Animal Cry" << endl;	// 1
	}
};

class Dog : public Animal {
public:
	void Cry() {
		cout << "Animal Cry" << endl;	// 1
	}
};

void foo ( Animal* p ) {
	p->Cry();
}

int main() {
	Animal a;
	a.Cry();

	Dog d;
	d.Cry();

	Animal* p = 0;

	int n;
	cin >> n;
	if(n==0)	p=&a;
	else		p=&d;
	p = &d;
	p->Cry();	// c++ 1, java 2, c# 1, objective-c 2
}