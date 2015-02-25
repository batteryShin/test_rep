// Protected 생성자 : 자신은 만들 수 없지만(추상적 개념) 자식은 만들 수 있게 하는 디자인 기법
class Animal {
protected:
	Animal() {}
};

class Dog : public Animal {
};

int main() {
//	Animal a;	// error. protected 생성자
	Dog d;
}
