#include <iostream>

using namespace std;

/*
 카메라 사용자와 제작자 사이의 규칙을 먼저 설계 (인터페이스, 계약서)
 - 규칙 : "모든 카메라는 아래 클래스로 부터 파생되어야 한다." 라는 말보다,
			"모든 카메라는 아래 인터페이스를 구현해야 한다." 라고 표현.
*/

class ICamera {
public:
	virtual ~ICamera() {}

	virtual void take() = 0;
};

class People {
public:
	void UseCamera(ICamera* p) { p->take(); }
};

class Camera : public ICamera {
public:
	void take() { cout << "Camera Take" << endl; }
};

class Camera2 : public ICamera {
public:
	void take() { cout << "Camera2 Take" << endl; }
};

int main() {
	Camera c;
	People p;
	p.UseCamera(&c);

	Camera2 c2;
	p.UseCamera(&c2);
}

/*
class Camera {
public:
	void take() { cout << "Camera Take" << endl; }
};

class Camera2 {
public:
	void take() { cout << "Camera2 Take" << endl; }
};

class People {
public:
	void UseCamera( Camera* p ) { p->take(); }
	void UseCamera( Camera2* p ) { p->take(); }
};


int main() {
	Camera c;
	People p;
	p->UseCamera(&c);

	Camera2 c2;
	p->UseCamera(&c2);
}
*/