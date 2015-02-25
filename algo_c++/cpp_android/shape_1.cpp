#include <iostream>
#include <vector>

using namespace std;

/*
 1. ��� ������ Ÿ������ ����� ��.

 2. ��� ������ ���� �θ� �ִٸ�, ��� ������ ��� ������ �� ����.

 3. ��� �ڽ��� ������ Ư¡�� �ִٸ�(Draw) �ݵ�� �θ𿡵� �־�� �Ѵ�.
	�׷��� �θ�� �ڽ��� ��� ����� �� �ִ�.
	=> LSP : Liskov Substitution Principle

 4. �θ��� �Լ� �� �ڽ��� �������ϴ� ��� �Լ��� �ݵ�� �����Լ� �̾�� �Ѵ�.
	"�����Լ��� �ƴ� �Լ��� ������ ���� ����" => Effective C++�� �ִ� �ݾ�

 5. ���Ȯ�忡 �����ְ�(����� ���߿� �߰��Ǿ, Open),
	�ڵ� �������� �����־��(���� �ڵ�� �����Ǹ� �ȵȴ�, Close) �Ѵٴ� �̷�(Principle) => OCP
	������(Polymorphism)�� OCP�� �����ϴ� ���� ���� ���� ����̴�.

 6. Prototype ������ ���� : �ڽ��� ���纻�� ����� �����Լ�
							java�� clonable(), C#�� IConable �������̽�
							�������� copy()�Լ� ���� ��� �� ������ ����

 7. �����丵 å�� �ִ� ���� : "Replace TypeCode(switch-case��) with Polymorphism"

 8. Template Method : ��� �ڽĵ��� ���� �˰����� �θ� �񰡻��Լ��� �����ϰ�(final),
						���ؾ� �ϴ� ���� ��å�� �����Լ�ȭ�ؼ�(private) �ڽ��� ������ �� �� �ְ��Ѵ�.
	=> C++���������� ���� "NVI(Non Virtual Interface)"��� Idioms�� �θ�

*/

class Shape {
	// ������ �ʴ� �ڵ�� ���ؾ� �ϴ� �ڵ�� �и��Ǿ�� �Ѵ�.
	// ���ؾ� �ϴ� ���� �ִٸ� ���� �Լ��� �̾Ƴ���.
private:
	virtual void DrawImpl() {
		cout << "Shape Draw" << endl;
	}

	// final : java���� �ڽĿ��� Ư�� �Լ��� ������ ���ϰ� �ϴ� Ű����
	// => C++11���� ����� ���� �߰���
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
	virtual void DrawImpl() { cout << "Rect Draw" << endl; }		// �ڽ��� �������ϴ� �Լ������� virtual�� ���� �ʿ������,
																// �������� ���� virtual�� ����
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
			cout << "���°�� ���� �ұ��? >> ";
			int k;
			cin >> k;

			// k��° ������ �����ؼ� v�� �߰�.
			v.push_back( v[k]->Clone() );		// �������� ���� ����. OCP ����.
		} else if( cmd==9 ) {
			for(int i=0; i<v.size(); i++) {
				v[i]->Draw();		// ������(Polymorphism) : �����Լ�ȣ���� ��Ȳ(��ü)�� ���� �ٸ� �Լ��� ȣ��
			}
		}
	}

}