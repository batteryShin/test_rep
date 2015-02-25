#include <iostream>

using namespace std;

/*
 ī�޶� ����ڿ� ������ ������ ��Ģ�� ���� ���� (�������̽�, ��༭)
 - ��Ģ : "��� ī�޶�� �Ʒ� Ŭ������ ���� �Ļ��Ǿ�� �Ѵ�." ��� ������,
			"��� ī�޶�� �Ʒ� �������̽��� �����ؾ� �Ѵ�." ��� ǥ��.
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