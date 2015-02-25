/*
	RTTI - Run Time Type Information
		: ���� �ð��� ������ p�� ��� ��ü�� ����Ű���� �����ϴ� ���(java�� Reflection)

	2. �����Լ� table�� ���� �����Ǵ� type_info�� ����ϹǷ� �����Լ��� 1�� �̻� �־�� �Ѵ�.
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
	// ����������...
	if( typeid(*p)==typeid(Dog) ) {
		//..
	}

	// �����Լ� table�� ���ؼ� �����Ǵ� type_info ��ü�� ������ ������.
	const type_info& t1 = typeid(*p);		// typeid(��ü)
	const type_info& t2 = typeid(Dog);		// typeid(Ŭ����)

	if(t1==t2) {
		cout << "p is a Dog" << endl;

		Dog* pDog = static_cast<Dog*>(p);
		pDog->color = 10;
	}
}
*/

void foo(Animal* p) {
//	Dog* pDog = static_cast<Dog*>(p);		// *�ڽ� = &�θ�, �� �ٿ�ĳ��Ʈ�� �������� ����
	Dog* pDog = dynamic_cast<Dog*>(p);		// �ٿ�ĳ��Ʈ �߻� �� 0�� ���ϵ�

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
