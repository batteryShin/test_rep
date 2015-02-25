#include <iostream>

using namespace std;

struct Plus {
	int operator()(int a, int b) {
		return a+b;
	}
};

int main() {
	Plus p;
	int n = p(1,2);

	cout << n << endl;

/*
	a + b; => a.operator+(b);
	a - b; => a.operator-(b);
	a(); => a.operator()();
	a(1,2); => a.operator()(1,2);
*/
}