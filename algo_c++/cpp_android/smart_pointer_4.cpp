#include <iostream>

using namespace std;

class Car {
	//....
	int mCount;
public:
	Car() : mCount(0) {}
	~Car() { cout << "ÀÚµ¿Â÷ ÆÄ±«" << endl; }

	void incStrong() { ++mCount; }
	void decStrong() { if( --mCount==0 ) delete this; }
};

int main() {
	Car* p1 = new Car;
	p1->incStrong();

	Car* p2 = p1;
	p2->incStrong();

	p2->decStrong();
	p1->decStrong();
}