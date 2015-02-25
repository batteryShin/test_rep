#include <iostream>

using namespace std;

class Cursor {
private:
	Cursor() {}
	Cursor(const Cursor& c);
	void operator=(const Cursor& c);

	static Cursor* sInstance;

public:
	static Cursor& getInstance() {
		if( sInstance==0 )	sInstance = new Cursor;
		return *sInstance;
	}
};

Cursor* Cursor::sInstance = 0;

int main() {
	Cursor& c1 = Cursor::getInstance();
}
