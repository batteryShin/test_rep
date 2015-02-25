#include <iostream>
#include "ioacademy.h"

#include <map>					// c++�� Ű ������ data�� �����Ѵ�.

using namespace std;
using namespace ioacademy;

class Clock;
map<int,Clock*> this_map;

class Clock {
	string name;

public:
	Clock(string s) : name(s) {}

	void Start(int ms) {
		int id = IoSetTimer(ms, timerRoutine);

		this_map[id] = this;
	}

	static void timerRoutine(int id) {
		Clock* const self = this_map[id];
		cout << self->name << endl;					// this->name�� �Ǿ�� �Ѵ�.
	}
};

int main() {
	Clock c1("AA");
	Clock c2("\tBB");
	c1.Start(1000);
	c2.Start(500);

	IoProcessMessage();
}

/*
void foo(int id) {
	cout << "foo : " << id << endl;
}

int main() {
	int id1 = IoSetTimer(1000, foo);
	int id2 = IoSetTimer(500, foo);

	IoProcessMessage();
}
*/