#include <iostream>
#include <string>

using namespace std;

typedef string String16;	// 안드로이드의 문자열 클래스는 String16

/*
	RTTI는 결국 타입의 정보를 담은 static 멤버 data 하나만 있으면 됨.
	- 규칙 1. 모든 클래스에는 static 멤버 변수 descriptor가 있어야 한다.
	- 규칙 2. 모든 클래스는 descriptor를 리턴하는
			가상함수 getInterfaceDescriptor()가 있어야 한다.
*/

class Animal {
public:
	static const String16 descriptor;						// type_info 역할
	virtual const String16& getInterfaceDescriptor() {		// typeid(x) 역할
		return descriptor;
	}
};
const String16 Animal::descriptor("Animal");

class Dog : public Animal {
public:
	static const String16 descriptor;						// type_info 역할
	virtual const String16& getInterfaceDescriptor() {		// typeid(x) 역할
		return descriptor;
	}
};
const String16 Dog::descriptor("Dog");

void foo( Animal* p ) {
	if(p->getInterfaceDescriptor()==Dog::descriptor) {
		cout << "p is a Dog" << endl;
	}
}

#define DECLARE_META_INTERFACE( INTERFACE )	\
	static const String16 descriptor;	\
	virtual const String16& getInterfaceDescriptor();

#define IMPLEMENT_META_INTERFACE( INTERFACE, NAME )	\
	const String16 INTERFACE::descriptor(NAME);	\
	const String16& INTERFACE::getInterfaceDescriptor()	{	\
		return INTERFACE::descriptor;	\
	}

// 안드로이드의 모든 native 서비스는 결국 getInterfaceDescriptor() 가 있음.
// 참조 : native/include/binder/IInterfae.h
class CameraService {
public:
	DECLARE_META_INTERFACE( CameraService );
};
IMPLEMENT_META_INTERFACE( CameraService, "kr.co.lg.CameraService");

int main() {
	Dog d;
	foo(&d);

	CameraService cam;
	cout << cam.getInterfaceDescriptor() << endl;
}