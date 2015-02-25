#include <iostream>

using namespace std;

// Effective-C++�� ���ڰ� ó�� ���� ���(Meyer's �̱���)
// ���� �ϳ��� ��ü�� static ���������� �Ǿ� �ִ�.
class Cursor {
private:
	Cursor() {}							// ��Ģ 1. private ������
public:
	static Cursor& getInstance() {		// ��Ģ 2. ���� �� ���� ��ü�� ����� static ��� �Լ�
		static Cursor instance;
		return instance;
	}
private:
	Cursor(const Cursor& c);			// ��Ģ 3. ����� ���� ���� - private ���� ������. ���� �Ѵ�.
	void operator=(const Cursor& c);

// c++11������ ���� ������ ����� ����ȭ
	Cursor(const Cursor& c) = delete;	// ����Ʈ ���� �����ڸ� �����޶�� ��...

};

int main() {
	Cursor& c1 = Cursor::getInstance();

	Cursor c2(c1);

}