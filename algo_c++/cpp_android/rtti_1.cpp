/*
	RTTI - Run Time Type Information
		: 실행 시간에 포인터 p가 어느 객체를 가르키는지 조사하는 기법(java의 Reflection)

	2. 가상함수 table에 의해 관리되는 type_info를 사용하므로 가상함수가 1개 이상 있어야 한다.
	3. if( typeid(*p)==typeid(Dog) )
	4. Dog* pDog = dynamic_cast<Dog*>(p);
*/

#include <iostream>

using namespace std;

class Animal {
public:
	virtual ~Animal() {}
};

class Dog : public Animal {
public:
	int color;
};
/*
void foo(Animal* p) {
	// 실전에서는...
	if( typeid(*p)==typeid(Dog) ) {
		//..
	}

	// 가상함수 table에 의해서 관리되는 type_info 객체의 참조를 꺼낸다.
	const type_info& t1 = typeid(*p);		// typeid(객체)
	const type_info& t2 = typeid(Dog);		// typeid(클래스)

	if(t1==t2) {
		cout << "p is a Dog" << endl;

		Dog* pDog = static_cast<Dog*>(p);
		pDog->color = 10;
	}
}
*/

void foo(Animal* p) {
//	Dog* pDog = static_cast<Dog*>(p);		// *자식 = &부모, 즉 다운캐스트를 조사하지 못함
	Dog* pDog = dynamic_cast<Dog*>(p);		// 다운캐스트 발생 시 0이 리턴됨

	if( pDog!=0 ) {
		//...
	}
	cout << pDog << endl;
}

int main() {
	Animal a;
	foo(&a);

	Dog d;
	foo(&d);
}
