#include <iostream>
#include <string>

using namespace std;

typedef string String16;	// �ȵ���̵��� ���ڿ� Ŭ������ String16

/*
	RTTI�� �ᱹ Ÿ���� ������ ���� static ��� data �ϳ��� ������ ��.
	- ��Ģ 1. ��� Ŭ�������� static ��� ���� descriptor�� �־�� �Ѵ�.
	- ��Ģ 2. ��� Ŭ������ descriptor�� �����ϴ�
			�����Լ� getInterfaceDescriptor()�� �־�� �Ѵ�.
*/

class Animal {
public:
	static const String16 descriptor;						// type_info ����
	virtual const String16& getInterfaceDescriptor() {		// typeid(x) ����
		return descriptor;
	}
};
const String16 Animal::descriptor("Animal");

class Dog : public Animal {
public:
	static const String16 descriptor;						// type_info ����
	virtual const String16& getInterfaceDescriptor() {		// typeid(x) ����
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

// �ȵ���̵��� ��� native ���񽺴� �ᱹ getInterfaceDescriptor() �� ����.
// ���� : native/include/binder/IInterfae.h
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