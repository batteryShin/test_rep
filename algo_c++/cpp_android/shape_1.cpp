#include <iostream>
#include <vector>

using namespace std;

/*
 1. 모든 도형을 타입으로 만들면 편리.

 2. 모든 도형의 공통 부모가 있다면, 모든 도형을 묶어서 관리할 수 있음.

 3. 모든 자식의 공통의 특징이 있다면(Draw) 반드시 부모에도 있어야 한다.
	그래야 부모로 자식을 묶어서 사용할 수 있다.
	=> LSP : Liskov Substitution Principle

 4. 부모의 함수 중 자식이 재정의하는 모든 함수는 반드시 가상함수 이어야 한다.
	"가상함수가 아닌 함수를 재정의 하지 말라" => Effective C++에 있는 격언

 5. 기능확장에 열려있고(기능이 나중에 추가되어도, Open),
	코드 수정에는 닫혀있어야(기존 코드는 수정되면 안된다, Close) 한다는 이론(Principle) => OCP
	다형성(Polymorphism)은 OCP를 만족하는 아주 좋은 설계 기술이다.

 6. Prototype 디자인 패턴 : 자신의 복사본을 만드는 가상함수
							java의 clonable(), C#의 IConable 인터페이스
							아이폰의 copy()함수 등이 모두 이 패턴의 응용

 7. 리팩토링 책에 있는 내용 : "Replace TypeCode(switch-case등) with Polymorphism"

 8. Template Method : 모든 자식들의 공통 알고리즘은 부모가 비가상함수로 제공하고(final),
						변해야 하는 세부 정책만 가상함수화해서(private) 자식이 재정의 할 수 있게한다.
	=> C++진영에서는 흔히 "NVI(Non Virtual Interface)"라는 Idioms로 부름

*/

class Shape {
	// 변하지 않는 코드와 변해야 하는 코드는 분리되어야 한다.
	// 변해야 하는 것이 있다면 가상 함수로 뽑아낸다.
private:
	virtual void DrawImpl() {
		cout << "Shape Draw" << endl;
	}

	// final : java에서 자식에게 특정 함수를 재정의 못하게 하는 키워드
	// => C++11에서 비슷한 것이 추가됨
public:
	void Draw() {
		cout << "Mutex Lock" << endl;
		DrawImpl();
		cout << "Mutex UnLock" << endl;
	}

	virtual Shape* Clone() { return new Shape(*this); }
};

class Rect : public Shape {
public:
	virtual void DrawImpl() { cout << "Rect Draw" << endl; }		// 자식이 재정의하는 함수에서는 virtual을 붙일 필요없지만,
																// 가독성을 위해 virtual을 붙임
	virtual Rect* Clone() { return new Rect(*this); }
};

class Circle : public Shape {
public:
	virtual void DrawImpl() { cout << "Circle Draw" << endl; }

	virtual Circle* Clone() { return new Circle(*this); }
};

class Triangle : public Shape {
public:
	virtual void DrawImpl() { cout << "Triangle Draw" << endl; }
};

int main() {
	vector<Shape*> v;

	while(1) {
		int cmd;
		cin >> cmd;

		if( cmd==1 )	v.push_back(new Rect);
		else if( cmd==2 )	v.push_back(new Circle);
		else if( cmd==8 ) {
			cout << "몇번째를 복사 할까요? >> ";
			int k;
			cin >> k;

			// k번째 도형을 복사해서 v에 추가.
			v.push_back( v[k]->Clone() );		// 다형성을 통한 구현. OCP 만족.
		} else if( cmd==9 ) {
			for(int i=0; i<v.size(); i++) {
				v[i]->Draw();		// 다형성(Polymorphism) : 동일함수호출이 상황(객체)에 따라 다른 함수를 호출
			}
		}
	}

}