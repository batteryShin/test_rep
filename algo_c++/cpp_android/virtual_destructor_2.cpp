#include <iostream>

using namespace std;

// CRTP�� ����ؼ� ���� �Ҹ����� overhead�� �����ϴ� ���..
//	���� : native/include/utils/RefBase.h
template<typename T> class LightRefBase {
	//....
	int mCount;
public:
	LightRefBase() : mCount(0) {}
	~LightRefBase() {}		// ���� �Ҹ���

	void incStrong() { ++mCount; }
	void decStrong() { if( --mCount==0 ) delete static_cast<T*>(this); }
};

class Car : public LightRefBase<Car> {
public:
	~Car() { cout << "Car destroyed" << endl; }
};

int main() {
	Car* p1 = new Car;
	p1->incStrong();
	p1->decStrong();
}