#include <iostream>

using namespace std;

class Animal {
public:
	void Cry() {
		cout << "Animal Cry" << endl;
	}
};

class Dog : public Animal {
	
};

void foo ( Animal* p ) {
	p->Cry();
}

int main() {
	Animal a;
	foo(&a);

	Dog d;
	foo(&d);
}