#include <iostream>

using namespace std;

// Effective-C++의 저자가 처음 만든 모양(Meyer's 싱글톤)
// 오직 하나의 객체가 static 지역변수로 되어 있다.
class Cursor {
private:
	Cursor() {}							// 규칙 1. private 생성자
public:
	static Cursor& getInstance() {		// 규칙 2. 오직 한 개의 객체를 만드는 static 멤버 함수
		static Cursor instance;
		return instance;
	}
private:
	Cursor(const Cursor& c);			// 규칙 3. 복사와 대입 금지 - private 복사 생성자. 선언만 한다.
	void operator=(const Cursor& c);

// c++11에서는 복사 금지의 기술이 문법화
	Cursor(const Cursor& c) = delete;	// 디폴트 복사 생성자를 지워달라는 뜻...

};

int main() {
	Cursor& c1 = Cursor::getInstance();

	Cursor c2(c1);

}